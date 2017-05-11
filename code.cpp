#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main(int arg,char* argv[])
{
	   int len =0,i=0,m=0,j=0;
	   string  line;
	   char ch;
	   ifstream myfile (argv[1]);
	   strcpy((char *)&line,"");
	   if (myfile.is_open())
	  {
	 while(myfile.get() != EOF)
	 {
		myfile.unget();
		while(getline(myfile,line,';'))
		{
			m=0;
			len = line.length();
			char line1[len+1];
		    ch=myfile.get();
		    for(i=0;i<len+1;i++)
		    {
		    	if(line[i]!=',')
		    	{
		    	  line1[m]=line[i];
		    	  m++;
		    	}
  		    }
		    i=0;
		    int k=0;
		     for(i=0;i<m-1;i=i+k)
		      {
		    	  j=i;
		    	  for(k=i;(k<(j+atoi(&ch)) && (j+atoi(&ch)<m));k++)
		          {
		    		  for(int l=k+1;l<j+atoi(&ch);l++)
		    		{
		                if(line1[l]>line1[k])
		             	{
		    		       len=line1[l];
		    		       line1[l]=line1[k];
		    		       line1[k]=len;
		             	}
		           	}
		          }
		    	}
		       for(i=0;i<m-1;i++)
		      {
		  		       cout<<line1[i];
		  		       if(i<m-2) cout << ',';
		  		       else
		  		    	   cout << ';';
		      }
		      cout << endl;
		     if(myfile.get()==EOF) break;
		    }
 	}

       myfile.close();
	  }
	  else cout << "Unable to open file";
	 	return 0;
}

