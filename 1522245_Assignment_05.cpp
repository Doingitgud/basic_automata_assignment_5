#include<iostream>
using namespace std;
class NFA
{
    struct Node
    {
        char tableValue;
        char states;
    };
    Node transition[5][5];
    void initializeTableValue()
    {
        transition[0][0].tableValue='-';
        transition[0][1].tableValue='-';
        transition[0][2].tableValue='-';
        transition[0][3].tableValue='-';
        transition[0][4].tableValue='-';
        transition[1][0].tableValue='-';
        transition[1][1].tableValue='1';
        transition[1][2].tableValue='0';
        transition[1][3].tableValue='-';
        transition[1][4].tableValue='-';
        transition[2][0].tableValue='-';
        transition[2][1].tableValue='0';
        transition[2][2].tableValue='1';
        transition[2][3].tableValue='-';
        transition[2][4].tableValue='-';
        transition[3][0].tableValue='-';
        transition[3][1].tableValue='-';
        transition[3][2].tableValue='-';
        transition[3][3].tableValue='0';
        transition[3][4].tableValue='1';
        transition[4][0].tableValue='-';
        transition[4][1].tableValue='-';
        transition[4][2].tableValue='-';
        transition[4][3].tableValue='1';
        transition[4][4].tableValue='0';
    }
    void initializeStates()
    {
        transition[0][0].states='a';
        transition[0][1].states='b';
        transition[0][2].states='c';
        transition[0][3].states='d';
        transition[0][4].states='e';
        transition[1][0].states='a';
        transition[1][1].states='b';
        transition[1][2].states='c';
        transition[1][3].states='d';
        transition[1][4].states='e';
        transition[2][0].states='a';
        transition[2][1].states='b';
        transition[2][2].states='c';
        transition[2][3].states='d';
        transition[2][4].states='e';
        transition[3][0].states='a';
        transition[3][1].states='b';
        transition[3][2].states='c';
        transition[3][3].states='d';
        transition[3][4].states='e';
        transition[4][0].states='a';
        transition[4][1].states='b';
        transition[4][2].states='c';
        transition[4][3].states='d';
        transition[4][4].states='e';
    }
public:
    NFA()
    {
        initializeTableValue();
        initializeStates();
    }
    void nfaOperation(string s)
    {
        int n=0;
        while(s[n]!=NULL)
        {
            n++;
        }
        int j=0, activeCounter=3, nextActiveCounter=0;
        bool fdie=false, check=true;
        int *activeArray=new int[5];
        int *nextActiveArray=new int[5];
        activeArray[0]=0;
        activeArray[1]=1;
        activeArray[2]=3;
        for(int i=3; i<5; i++)
        {
            activeArray[i]=-1;
        }
        for(int i=0; i<5; i++)
        {
            nextActiveArray[i]=-1;
        }

        while(j!=n)
        {

            for(int a=0; a<activeCounter; a++)
            {
                for(int i=0; i<5; i++)
                {
                    if(s[j]==transition[activeArray[a]][i].tableValue)
                    {
                        nextActiveArray[nextActiveCounter]=i;
                        nextActiveCounter++;
                    }
                    else if(s[j]!='0'&&s[j]!='1')
                    {
                        fdie=true;
                        break;
                    }
                }
                if(fdie)
                {
                    break;
                }

            }
            if(fdie)
            {
                break;
            }
            activeCounter=nextActiveCounter;
            for(int i=0; i<5; i++)
            {
                activeArray[i]=-1;
            }
            for(int i=0; i<activeCounter; i++)
            {
                activeArray[i]=nextActiveArray[i];
            }
            nextActiveCounter=0;
            for(int i=0; i<5; i++)
            {
                nextActiveArray[i]=-1;
            }
            j++;

        }
        if(fdie)
        {
            check=false;
            cout<<"Invalid input\n";
        }
        char state[]= {'a','b','c','d','e'};
        for(int i=0; i<activeCounter; i++)
        {
            if((state[activeArray[i]]=='b'||state[activeArray[i]]=='d')&&fdie==false)
            {
                check=false;
                cout<<"yes\n";
                break;
            }
        }
        if(check)
        {
            cout<<"No\n";
        }
    }

};
int main()
{
    string s;
    char p='\0';
    NFA evenOdd;
    cout<<"Input a binary string : \n";
    cin>>s;
    evenOdd.nfaOperation(s);
    while(true)
    {
        cout<<"Do you want to continue (y/n): ";
        cin>>p;
        if(p=='y')
        {
            cout<<"Input a binary string : \n";
            cin>>s;
            evenOdd.nfaOperation(s);
        }
        else if(p=='n')
        {
            break;
        }
    }
    cout<<"Thank you for using our NFA\n";
    return 0;
}
