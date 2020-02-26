#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
    char continueProgram = 'y';

    string filename = argv[1];
    while(true)
    {
      if(argc != 2)
      {
          cout << "USAGE: assignment1 <filename>" << endl;
          return 0;
      }

      double mean = 0.0;
      double stdv = 0.0;
      double var = 0.0;
      double total_sum = 0;
      int line_count=0;

      int A=0;
      int C=0;
      int G=0;
      int T=0;

      int AA=0;
      int AC=0;
      int AG=0;
      int AT=0;

      int CA=0;
      int CC=0;
      int CG=0;
      int CT=0;

      int GA=0;
      int GC=0;
      int GG=0;
      int GT=0;

      int TA=0;
      int TC=0;
      int TG=0;
      int TT=0;

      //------------------------------------------------

      // Read file lines
      //string filename = argv[1];
      ifstream myfile;
      myfile.open (filename);

      for( std::string line; getline( myfile, line ); )
      {
          int length = line.length();

          line.erase(std::remove(line.begin(), line.end(), '\0'), line.end());

          for(int x = 0; x<length; ++x)
          {
            line[x] = toupper(line[x]);
          }

          for(int i=0;i<length;++i)
          {
            string nuc = line.substr(i,1);
            //cout << nuc <<" ";

            if(nuc=="A") A++;
            if(nuc=="C") C++;
            if(nuc=="G") G++;
            if(nuc=="T") T++;
          }

          for(int i=0;i<length;i=i+2)
          {
             string pair = line.substr(i,2);

             if(pair=="AA") AA++;
             if(pair=="AC") AC++;
             if(pair=="AG") AG++;
             if(pair=="AT") AT++;

             if(pair=="CA") CA++;
             if(pair=="CC") CC++;
             if(pair=="CG") CG++;
             if(pair=="CT") CT++;

             if(pair=="GA") GA++;
             if(pair=="GC") GC++;
             if(pair=="GG") GG++;
             if(pair=="GT") GT++;

             if(pair=="TA") TA++;
             if(pair=="TC") TC++;
             if(pair=="TG") TG++;
             if(pair=="TT") TT++;



          }

          //cout << line << "," << length << endl;

          total_sum += (length);
          ++line_count;

      }

      myfile.close();


      //------------------------------------------------


      //Statistics calculations
      mean = total_sum/line_count;

      myfile.open (filename);
      for( std::string line; getline( myfile, line ); )
      {
          int length = line.length();
          var+= pow((length-mean),2);
      }
      var = var/line_count;
      stdv=sqrt(var);

      myfile.close();


      // Write output to file
      ofstream fout;
      fout.open("davida.txt");
      //,ios::app

      //------------------------------------------------

      fout<<" -----------------------------------------------------"<<endl;
      fout<<"{ David Aaron || ID: 2287562 || CPSC 350 -Assignment 1 }" <<endl;
      fout<<" -----------------------------------------------------"<<endl;

      fout << " "<<endl;
      fout << " "<<endl;

      //------------------------------------------------



      fout << "----={DNA STRING STATISTICS}=----"<< endl;

      fout << "Total Length: " << total_sum << endl;
      fout << "DNA String Length Mean: " << mean << endl;
      fout << "DNA String Length Variance: " << var << endl;
      fout << "DNA String Length StdDev: " << stdv << endl;


      fout << " "<<endl;
      fout << " "<<endl;

      fout << "------={NUCLEOTIDE PROBABILITY}=------"<< endl;
      fout << "A: " << A/total_sum << endl;
      fout << "C: " << C/total_sum << endl;
      fout << "G: " << G/total_sum << endl;
      fout << "T: " << T/total_sum << endl;


      fout << " "<<endl;
      fout << " "<<endl;

      fout << "----={NUCLEOTIDE BIGRAM PROBABILITY}=----"<< endl;

      fout << "AA: " << AA/total_sum << endl;
      fout << "AC: " << AC/total_sum << endl;
      fout << "AG: " << AG/total_sum << endl;
      fout << "AT: " << AT/total_sum << endl;

      fout << "CA: " << CA/total_sum << endl;
      fout << "CC: " << CC/total_sum << endl;
      fout << "CG: " << CG/total_sum << endl;
      fout << "CT: " << CT/total_sum << endl;

      fout << "CA: " << CA/total_sum << endl;
      fout << "CC: " << CC/total_sum << endl;
      fout << "CG: " << CG/total_sum << endl;
      fout << "CT: " << CT/total_sum << endl;

      fout << "GA: " << GA/total_sum << endl;
      fout << "GC: " << GC/total_sum << endl;
      fout << "GG: " << GG/total_sum << endl;
      fout << "GT: " << GT/total_sum << endl;

      fout << "TA: " << TA/total_sum << endl;
      fout << "TC: " << TC/total_sum << endl;
      fout << "TG: " << TG/total_sum << endl;
      fout << "TT: " << TT/total_sum << endl;
      fout << "--------------------------------"<< endl;

      fout.close();


      //------------------------------------------------
      //Gausian Distribution

      string random_string = "";
      double c = 0;
      double D = 0;

      srand(time(NULL));


      //Appending 1000 random strings
      myfile.open (filename);

      fout.open("davida.txt", ios::app);

      fout << " "<< endl;
      fout << "[ 1000 DNA STRINGS || Mean Length: " << mean << " || Length StdDev: "<< stdv << " ] "<< endl;
      fout << " "<< endl;


      for(int i =0; i<1000; ++i)
      {

        double random1 = ((double) rand() / (RAND_MAX));
        double random2 = ((double) rand() / (RAND_MAX));


        c = sqrt(-2 * log10(random1)) * cos(2 * M_PI * random2);

        D = (stdv * c) + mean;

        D = ceil(D);

        for (int j = 0; j < D; ++j)
        {
          double randomChar = ((double) rand() / (RAND_MAX));

          if(randomChar <= (A/(total_sum)))
          {
            random_string+="A";
          }
          else if((randomChar > (A/(total_sum))) && (randomChar <=(C/(total_sum))+(A/(total_sum))))
          {
            random_string+="C";
          }
          else if((randomChar > (C/(total_sum))) && (randomChar <=(C/(total_sum))+(A/(total_sum))+(G/(total_sum))))
          {
            random_string+="G";
          }
          else if((randomChar >(C/(total_sum))+(A/(total_sum))+(G/(total_sum))))
          {
            random_string+="T";
          }

        }
        fout <<random_string << endl;
        random_string = "";
      }

      cout<<"Enter 'y' to continue and add another file [ENTER ANY OTHER CHARACTER TO EXIT]:";
      cin>>continueProgram;
      if (continueProgram !='y') break;


      cout<<"Enter file name: ";

      cin>> filename;
      cout<<filename;

    }
    return 0;
}
