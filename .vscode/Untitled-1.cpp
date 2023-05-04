#include <iostream>
#include <cmath>
#include <limits>
#include <numeric>

//check points Number &  Position
bool checkPoints(std::string fullAddress, int fullLength) {
    int pointCount=0;
    for (int i=1;i<fullLength;i++) {
        if (fullAddress[i]=='.') {
            pointCount++;
        }
        if (fullAddress[0]=='.'
            || fullAddress[fullLength-1]=='.'
            || fullAddress[i]==fullAddress[i-1] && fullAddress[i]=='.') 
        {
            return false;
            break;                
        }
    }
    if (pointCount!=3) {
        return false;      
    } else {
        return true;
    }
}
//check points Number &  Position

//mind points pos
int pointPos(std::string fullAddress, int j) {
    int b;
    std::string addy=fullAddress;
    for (int i=1;i<=j;i++) {
        b=addy.find('.');
        addy[addy.find('.')]=0;
    }
    return b;
}
//mind points pos

//extract numbers
std::string extractNumber(std::string fullAddress, int j) {
    if (j==1) {
        return fullAddress.substr(0,pointPos(fullAddress, j));
    } else if (j==4) {
        return fullAddress.substr(pointPos(fullAddress, j-1)+1,fullAddress.length()-pointPos(fullAddress, j-1));
    } else {
        return fullAddress.substr(pointPos(fullAddress, j-1)+1,pointPos(fullAddress, j)-pointPos(fullAddress, j-1)-1);
    }
}
//extract numbers

//check Numbers
bool checkNumbers(std::string number) {
    if (number[0]=='0' && number.length()>1|| number.length()>3) {
        return false;
    } else {
        for (int i=0;i<number.length();i++) {
            if (!isdigit(number[i])) {
                return false;
                break;
            }
        }
    }
    return true;
}
//check Numbers














  
int main() {
    while (true) {
        std::string fullAddress;
        std::cout<<"Введите адрес: ";
        std::cin>>fullAddress;

        bool rightPoints;

        //check input data  
        if (std::cin.fail() || std::cin.peek()!='\n') {
            std::cout<<"Input Error";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        //check input data
        
        //check points Number &  Position
        } else {
            
            int fullLength=fullAddress.length();
            rightPoints=checkPoints(fullAddress,fullLength);                                          //rightPoints
            //check points Number &  Position

            //extract numbers
            std::string number[5];
            int j;
            for (j=1;j<=4;j++) {
                number[j]=extractNumber(fullAddress,j);
            }
            //extract numbers

            //check numbers
            bool rightNumbers=true;
            for (j=1;j<=4 && rightNumbers;j++) {
                rightNumbers*=checkNumbers(number[j]);                                       //rightNumbers
            }
            //check numbers

            //stringtoint
            int numberInt[5];
            for (j=1;j<=4 && rightPoints && rightNumbers;j++) {
                numberInt[j]=std::stoi(number[j]);                                         
            }
            //stringtoint

            //check values
            bool rightValue=true;
            for (j=1;j<=4;j++) {
                if (numberInt[j]<0 || numberInt[j]>255) {
                    rightValue=false;                                                       //rightValue
                }                                         
            }
            //check values


            if (rightPoints && rightNumbers && rightValue) {
                std::cout<<"Address is correct\n";
            } else {
                std::cout<<"Address is incorrect!\n";
            }
        }


    }
}

    
    

    


