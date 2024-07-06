// Do NOT add any other includes
#include <string> 
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

struct StringHash{
    string str;
    int count;
};

class Dict {
private:
    // You can add attributes/helper functions here

public: 
    int p[128]={};
    vector<vector<StringHash> > HashMap;
    int size = 0;
    int capacity = 512;

    /* Please do not touch the attributes and 
    functions within the guard lines placed below  */
    /* ------------------------------------------- */
    Dict();

    ~Dict();

    int hash(string str);

    void insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence);

    int get_word_count(string word);

    void dump_dictionary(string filename);

    /* -----------------------------------------*/
};