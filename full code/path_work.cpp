        #include<iostream>
        #include<fstream>
        #include<stdio.h>
        
        using namespace std;

//string opption();

char path()
{
   char a ='a';
    return a ;
}

void opption()
{
    cout<<opption("a");
    cout<<"i am opption. \n";
}
string opption(string a)
{
    string c=a;
  string b="path";
   
  cout<<"running\n";
   return b ;
  
}

main()
{
   //string a;
    
    cout<<"main";
    opption();

}
