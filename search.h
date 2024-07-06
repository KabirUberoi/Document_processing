
// Do NOT add any other includes
#include <string> 
#include <vector>
#include <iostream>
#include "Node.h"
using namespace std;


class Stringnode{
public:
string sent;
int bc;
int pag;
int senno;
int para;
Stringnode(int book,int page,int par,int senn,string sentence){
  sent=sentence;
  bc=book;
  pag=page;
  senno=senn;
  para=par;

}
};

class SearchEngine {
private:
  
    vector<Stringnode*>stsentence;

public: 
    /* Please do not touch the attributes and 
    functions within the guard lines placed below  */
    /* ------------------------------------------- */
    SearchEngine();

    ~SearchEngine();

    void insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence);

    Node* search(string pattern, int& n_matches);

    /* -----------------------------------------*/
};