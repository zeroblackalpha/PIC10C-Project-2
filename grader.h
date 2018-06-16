#ifndef GRADER_H
#define GRADER_H

#include <vector>
#include <QObject>
#include <string>
#include <algorithm>
#include "qstring.h"


using std::vector;

// Custom grader object to recieve UI element signals
class Grader : public QObject {

    Q_OBJECT

public:
    Grader(){}
    ~Grader(){}

    // Calculate grade based on grading scheme and course
    void calculateGrade(){
        double gradeNum = 0.0;
        if (tab && scheme){
            for (int i = 0; i < 3; ++i){
                gradeNum += PIC10C[i];
            }
            gradeNum /= 3;
            gradeNum *= 0.15;
            gradeNum += PIC10C[4] * 0.35;
            gradeNum += PIC10C[5] * 0.50;
        }
        else if (tab){
            for (int i = 0; i < 3; ++i){
                gradeNum += PIC10C[i];
            }
            gradeNum /= 3;
            gradeNum *= 0.15;
            gradeNum += PIC10C[3] * 0.25;
            gradeNum += PIC10C[4] * 0.35;
            gradeNum += PIC10C[5] * 0.30;
        }
        else if (scheme){
            double temp = PIC10B[0];
            for (int i = 0; i < 7; ++i){
                if (temp > PIC10B[i])
                    temp = PIC10B[i];
                gradeNum += PIC10B[i];
            }
            gradeNum -= temp;
            gradeNum /= 6;
            gradeNum *= 0.25;
            gradeNum += std::max(PIC10B[7],PIC10B[8]) * 0.3;
            gradeNum += PIC10B[9] * 0.44;
        }
        else{
            double temp = PIC10B[0];
            for (int i = 0; i < 7; ++i){
                if (temp > PIC10B[i])
                    temp = PIC10B[i];
                gradeNum += PIC10B[i];
            }
            gradeNum -= temp;
            gradeNum /= 6;
            gradeNum *= 0.25;
            gradeNum += PIC10B[7] * 0.2;
            gradeNum += PIC10B[8] * 0.2;
            gradeNum += PIC10B[9] * 0.35;
        }
        grade = QString::fromStdString(std::to_string(gradeNum) + "%");
    }

// Recieve User Inputs
public slots:
    void updateSchema(bool value){
        if (value)
            scheme = !scheme;
        calculateGrade();
        emit valueChanged(grade);
    }
    void updateTab(int value){
        tab = value;
        calculateGrade();
        emit valueChanged(grade);
    }
    void updatePIC10BHW1(double value){
        PIC10B[0] = value;
        calculateGrade();
        emit valueChanged(grade);
    }
    void updatePIC10BHW2(double value){
        PIC10B[1] = value;
        calculateGrade();
        emit valueChanged(grade);
    }
    void updatePIC10BHW3(double value){
        PIC10B[2] = value;
        calculateGrade();
        emit valueChanged(grade);
    }
    void updatePIC10BHW4(double value){
        PIC10B[3] = value;
        calculateGrade();
        emit valueChanged(grade);
    }
    void updatePIC10BHW5(double value){
        PIC10B[4] = value;
        calculateGrade();
        emit valueChanged(grade);
    }
    void updatePIC10BHW6(double value){
        PIC10B[5] = value;
        calculateGrade();
        emit valueChanged(grade);
    }
    void updatePIC10BHW7(double value){
        PIC10B[6] = value;
        calculateGrade();
        emit valueChanged(grade);
    }
    void updatePIC10BMT1(double value){
        PIC10B[7] = value;
        calculateGrade();
        emit valueChanged(grade);
    }
    void updatePIC10BMT2(double value){
        PIC10B[8] = value;
        calculateGrade();
        emit valueChanged(grade);
    }
    void updatePIC10BFE(double value){
        PIC10B[9] = value;
        calculateGrade();
        emit valueChanged(grade);
    }
    void updatePIC10CHW1(double value){
        PIC10C[0] = value;
        calculateGrade();
        emit valueChanged(grade);
    }
    void updatePIC10CHW2(double value){
        PIC10C[1] = value;
        calculateGrade();
        emit valueChanged(grade);
    }
    void updatePIC10CHW3(double value){
        PIC10C[2] = value;
        calculateGrade();
        emit valueChanged(grade);
    }
    void updatePIC10CMT(double value){
        PIC10C[3] = value;
        calculateGrade();
        emit valueChanged(grade);
    }
    void updatePIC10CFP(double value){
        PIC10C[4] = value;
        calculateGrade();
        emit valueChanged(grade);
    }
    void updatePIC10CFE(double value){
        PIC10C[5] = value;
        calculateGrade();
        emit valueChanged(grade);
    }

// Update Grade
signals:
    void valueChanged(QString newValue);

private:
    vector<double> PIC10B = vector<double>(10,0.0);
    vector<double> PIC10C = vector<double>(6,0.0);
    bool scheme = false;
    int tab = 0;
    QString grade = QString::fromStdString("0.0%");
};

#endif // GRADER_H
