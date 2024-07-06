#include "search.h"
#include<iostream>

void RabinKarp(Stringnode *s, string pattern, vector<Node*> &offsets){
  int PatSum = 0; int tempSum = 0; 
    for(int i=0; i<pattern.size(); i++){
        PatSum+=pattern[i];
        tempSum+=s->sent[i];
    }
    for(int i=0; i<=(s->sent.size()-pattern.size()); i++){
        if(PatSum == tempSum){
          string check = s->sent.substr(i,pattern.length()); 
          if(check == pattern){
            Node*fpat=new Node(s->bc,s->pag,s->para,s->senno,i);
            offsets.push_back(fpat);
          }
        }
        if(i<s->sent.size()-pattern.length()){
            tempSum+=s->sent[i+pattern.length()];
        };
        tempSum-=s->sent[i];
    }
}
SearchEngine::SearchEngine(){
  
}
SearchEngine::~SearchEngine(){
  for(int i=0;i<stsentence.size();i++){
      delete stsentence[i];
     }
}

void SearchEngine::insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence){
  string updated;
  for(char ch:sentence){
    updated+=tolower(ch);
  }
  Stringnode *newNode = new Stringnode(book_code, page, paragraph, sentence_no, updated);
  stsentence.push_back(newNode);
}

Node* SearchEngine::search(string pattern, int& n_matches){
  vector<Node*>offsets;
  string updated;
  for(char ch:pattern){
    updated+=tolower(ch);
  }
  for(int i=0;i<stsentence.size();i++){
    if(stsentence[i]->sent.size()>=pattern.size()){
      RabinKarp(stsentence[i],updated,offsets);
    }
  }
  n_matches=offsets.size();
  if(offsets.size()==0){
    return nullptr;
  }
  else{
    Node*head=offsets[0];
    Node*temp=head;
    for(int i=1;i<offsets.size();i++){
      temp->right=offsets[i];
      temp=temp->right;
    }
    return head;
  }
  
}