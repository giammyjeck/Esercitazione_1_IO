#include<iostream>
#include<fstream>
#include<iomanip>


// function that map a double from [1,5] to [-1,2]
double map(double x){
    double y = (3.0/4.0)*x -(7.0/4.0);
    return y;
}


int main()
{


    //open the reading file
    //
    std::string fileName = "data.csv"; // file name
    std::ifstream fileInput(fileName); // create istream object and open file

    if(fileInput.fail())
    {
        std::cerr << "File does not exist" << std::endl;
        return 1;
    }

    //create the writing file
    //
    std::string fileName2 = "reading.csv";
    std::ofstream fileOutput(fileName2);  //create and open the new file

    if(fileOutput.fail()) //check output file
    {
        std::cerr << "File hasn't been created" << std::endl;
        return 2;
    }

    // writing header
    fileOutput << "#" <<";" <<"N mean" << "\n";  //"\n" or endl ??

    double value = 0.0;
    unsigned int countVal = 1;
    double sum = 0.0;


    while (fileInput >> value){
        double mapped = map(value);
        sum = sum + mapped;
        double mean = sum/countVal;
        fileOutput << countVal << ";"<< std::scientific << std::setprecision(16) << mean << std::endl;
        countVal = countVal+1;
    }


    fileInput.close();
    fileOutput.close();

    return 0;
}

