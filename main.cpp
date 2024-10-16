#include <vector>
#include <array>
#include <set>
#include <sstream>
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>

typedef std::unordered_map<int, std::string> inner_map;



#include "verb_map.cpp"
#include "outer_verb_map.cpp"
#include "nom_map.cpp"
#include "outer_nom_map.cpp"





struct Lemma {

  long int lemma_id{};
  std::string lemma_form{};
  std::string morph_replace{};
  std::string second_velar{};
  std::string poss_doublet{};
  short int loan_place{};
  short int long_adj{};
  bool non_assim{};
  std::string eng_trans{};
  std::string pre_jot{};
  std::string etym_disc{};
  bool bad_etym{};
  std::string loan_source{};
  std::string conj_type{};
  short int noun_verb{};



  friend bool operator== (const Lemma &l1, const Lemma &l2);
  friend bool operator< (const Lemma &l1, const Lemma &l2);


  Lemma(
    long int lemma_id_, std::string lemma_form_ = "", std::string morph_replace_ = "", std::string second_velar_ = "", std::string poss_doublet_ = "", short int loan_place_ = 0, short int long_adj_ = 0, bool non_assim_ = false, std::string eng_trans_ = "", std::string pre_jot_ = "", std::string etym_disc_ = "",  bool bad_etym_ = false, std::string loan_source_ = "", std::string conj_type_ = "", short int noun_verb_ = 0
    ) : lemma_id{ lemma_id_ }, lemma_form{ lemma_form_ }, morph_replace{ morph_replace_ }, second_velar{ second_velar_ }, poss_doublet { poss_doublet_ }, loan_place { loan_place_}, long_adj { long_adj_ }, non_assim { non_assim_ }, eng_trans { eng_trans_ }, pre_jot { pre_jot_ }, etym_disc { etym_disc_ }, bad_etym { bad_etym_ }, loan_source { loan_source_ }, conj_type { conj_type_ }, noun_verb {noun_verb_}{

  }

};
bool operator== (const Lemma &l1, const Lemma &l2)
{
    return (l1.lemma_id == l2.lemma_id);
}
bool operator< (const Lemma &l1, const Lemma &l2)
{
    return (l1.lemma_id < l2.lemma_id);
}

std::string str_Truncate(std::string str1, int lop_off) {
  
  int end_pos = str1.length();
  int cut_pos = end_pos - lop_off;
  std::string str_cut = str1.replace(cut_pos, lop_off, "");
  return str_cut;
                                   
}

#include "lemlist_2.h"
#include "conj_type_enum.h"
#include "verb_cleaning.h"
#include "noun_cleaning.h"
#include "functions.h"

#include "noun_Flect.h"
#include "changeLemma_field.h"



std::string Dejotate(std::string cs_word) {
  
  std::string str1, str2;
  int x, y;
  for (int letno = 0; letno < 33; letno++) {

    switch (letno) {

      case 0:
        str1.assign("strj");
        str2.assign("šћŕ");
        break;
      case 1:
        str1.assign("stj");
        str2.assign("šћ");
        break;
      case 2:
        str1.assign("zdj");
        str2.assign("žђ");
        break;
      case 3:
        str1.assign("slj");
        str2.assign("šĺ");
        break;
      case 4:
        str1.assign("zlj");
        str2.assign("žĺ");
        break;
      case 5:
        str1.assign("znj");
        str2.assign("žń");
        break;
      case 6:
        str1.assign("snj");
        str2.assign("šń");
        break;
      case 7:
        str1.assign("trj");
        str2.assign("ћŕ");
        break;
      case 8:
        str1.assign("drj");
        str2.assign("ђŕ");
        break;
      case 9:
        str1.assign("tvj");
        str2.assign("ћvĺ");
        break;
      case 10:
        str1.assign("bj");
        str2.assign("bĺ");
        break;
      case 11:
        str1.assign("pj");
        str2.assign("pĺ");
        break;
      case 12:
        str1.assign("mj");
        str2.assign("mĺ");
        break;
      case 13:
        str1.assign("vj");
        str2.assign("vĺ");
        break;
      case 14:
        str1.assign("kt");
        str2.assign("ћ");
        break;
      case 15:
        str1.assign("gt");
        str2.assign("ћ");
        break;
      case 16:
        str1.assign("tj");
        str2.assign("ћ");
        break;
      case 17:
        str1.assign("dj");
        str2.assign("ђ");
        break;
      case 18:
        str1.assign("nj");
        str2.assign("ń");
        break;
      case 19:
        str1.assign("lj");
        str2.assign("ĺ");
        break;
      case 20:
        str1.assign("rj");
        str2.assign("ŕ");
        break;
      case 21:
        str1.assign("sj");
        str2.assign("š");
        break;
      case 22:
        str1.assign("zj");
        str2.assign("ž");
        break;
      case 23:
        str1.assign("čj");
        str2.assign("č");
        break;
      case 24:
        str1.assign("šj");
        str2.assign("š");
        break;
      case 25:
        str1.assign("žj");
        str2.assign("ž");
        break;
      case 26:
        str1.assign("zž");
        str2.assign("žǯ");
          break;
      case 27:
        str1.assign("jj");
        str2.assign("j");
          break;
      case 28:
        str1.assign("gj");
        str2.assign("ž");
          break;
      case 29:
        str1.assign("kj");
        str2.assign("č");
          break;
      case 30:
        str1.assign("xj");
        str2.assign("š");
          break;
      case 31:
        str1.assign("ђj");
        str2.assign("ђ");
          break;
      case 32:
        str1.assign("ńj");
        str2.assign("ń");
          break;
    }

    do {
      x = cs_word.find(str1);
      if (x == -1)  {break;}
      y = str1.length();
      cs_word.replace(x, y, str2); 
    }
    while (x != -1);


  }
  return cs_word;
}


std::string deep_clean_Cyr(std::string form_cell) {

  std::string str1;
  std::string str2;
  int x = 0;
//  int q = 0;
  int y;


#include "deep_clean_cyr_rep.h"

     do {
        x = form_cell.find(str1);
        if (x == -1) { break; }

        y = str1.length();
        form_cell.replace(x, y, str2);
     } while (x != -1);
  //   cout << q << " times." << "\n";
     }
    return form_cell;
}





std::string clean_Cyr(std::string form_cell) {

  std::string str1;
  std::string str2;
  int x = 0;
//  int q = 0;
  int y;


#include "clean_cyr_rep.h"

     do {
        x = form_cell.find(str1);
        if (x == -1) { break; }

        y = str1.length();
        form_cell.replace(x, y, str2);
     } while (x != -1);
  //   cout << q << " times." << "\n";
     }
    return form_cell;
}

std::string glagoliticise(std::string form_cell) {

  std::string str1;
  std::string str2;
  int x = 0;
//  int q = 0;
  int y;


#include "nonKF_glag_rep.h"

     do {
        x = form_cell.find(str1);
        if (x == -1) { break; }

        y = str1.length();
        form_cell.replace(x, y, str2);
     } while (x != -1);
  //   cout << q << " times." << "\n";
     }
    return form_cell;
}


int addDummyrow(std::string filename){
  std::vector<std::string> row;
 std::ifstream inFile(filename);
if(!inFile) {
  return false;
}
 std::string line, column;
 std::ofstream outFile;
outFile.open("dummyrow.csv");


while(std::getline(inFile, line)) {
   std::stringstream ss(line);

outFile << line << ',' << std::endl;
}
outFile.close();
inFile.close();
return true;
}

int form_col_no(std::string filename) {
  std::vector<std::string> row;
 std::ifstream inFile(filename);
 std::string line, column;
 std::getline(inFile, line);
 std::stringstream ss(line);
 int num_of_columns = 0;
 while(std::getline(ss, column, ','))
  {
    row.emplace_back(column);
    num_of_columns++;
  }
std::string form = "form";
int j = 0;
/* for(int i = 0; i < num_of_columns; i++) {
std::cout << row[i] << ",";
}
std::cout << std::endl;
*/

while(row[j].find(form) == -1) {
  j = j + 1;
  if(j == num_of_columns){std::cout << "No 'form' header was found" << std::endl; j = 999; break;}
}
return j;
}

int lemma_id_col_no(std::string filename) {
  std::vector<std::string> row;
 std::ifstream inFile(filename);
 std::string line, column;
 std::getline(inFile, line);
 std::stringstream ss(line);
 int num_of_columns = 0;
 while(std::getline(ss, column, ','))
  {
    row.emplace_back(column);
    num_of_columns++;
  }
std::string lemma_id = "lemma_id";
int j = 0;
/* for(int i = 0; i < num_of_columns; i++) {
std::cout << row[i] << ",";
}
std::cout << std::endl;
*/
while(row[j].find(lemma_id) == -1) {
  j = j + 1;
  if(j == num_of_columns){std::cout << "No 'lemma_id' header was found" << std::endl; j = 999; break;}
}
return j;
}

int morphology_col_no(std::string filename) {
  std::vector<std::string> row;
 std::ifstream inFile(filename);
 std::string line, column;
 std::getline(inFile, line);
 std::stringstream ss(line);
 int num_of_columns = 0;
 while(std::getline(ss, column, ','))
  {
    row.emplace_back(column);
    num_of_columns++;
  }
std::string morphology = "morphology";
int j = 0;
/* for(int i = 0; i < num_of_columns; i++) {
std::cout << row[i] << ",";
}
std::cout << std::endl;
*/
while(row[j].find(morphology) == -1) {
  j = j + 1;
  if(j == num_of_columns){std::cout << "No 'morphology' header was found" << std::endl; j = 999; break;}
}
return j;
}



void createBasefiles(std::string filename2, int form_pos, int lemma_id_pos, int morphology_pos) {

   std::vector<std::string> row;

  std::ifstream inFile("dummyrow.csv");

  std::string line1;
  std::getline(inFile, line1);

  std::string line, column;
  std::ofstream outFile;
  std::ofstream outFile2;

  outFile.open(filename2);
  outFile2.open("deep_cleaned.csv");


while(std::getline(inFile, line)) {

    std::stringstream ss(line);


       while(std::getline(ss, column, ','))
        {
          row.emplace_back(column);
        }

std::string cyr_form = row[form_pos];
std::string lemma_id = row[lemma_id_pos];
std::string morph_tag = row[morphology_pos];

outFile << clean_Cyr(cyr_form) << "|" << glagoliticise(clean_Cyr(cyr_form)) << std::endl;
outFile2 << deep_clean_Cyr(cyr_form) << "|" << lemma_id << "|" << morph_tag << "|" << std::endl;
//outFile << cell_content << endl;

row.clear();
}
inFile.close();
outFile.close();
}

std::string boolToStr(bool non_assim) {
  if (non_assim == false) return "";
  else return "W";
}



void Reconstruct(std::string filename, std::string filename2, std::string filename3) {

  std::vector<std::string> row;

 std::ifstream inFile(filename);
 std::ifstream inFile2(filename2);

 std::string line, column;
 std::string line2;
 std::ofstream outFile;
 outFile.open(filename3);
while(std::getline(inFile, line)) {

   std::stringstream ss(line);

    //this takes the line spat out by getline and goes through it, adding the characters up to the pipe separator to the vector row, then it hits the separator and starts again, but this time from the character after the pipe separator, i.e. the next cell
      while(std::getline(ss, column, '|'))
       {
         row.emplace_back(column);
       }

std::string cyr_id = row[0];
std::string lemma_id_str = row[1];
long int lemma_id = std::stol(lemma_id_str);
std::string morph_tag = row[2];


std::set<Lemma>::iterator it;



it = lemma_list.find(lemma_id);
if (it != lemma_list.end()) {
Lemma lemma = *it;    //retrieve the object stored in the memory address of the iterator


changeLemma_field(lemma, morph_tag, cyr_id); //pass object by reference to a function so I can change one of its members directly

std::getline(inFile2, line2);

std::string dejotated_word = Dejotate(lemma.lemma_form);

if(dejotated_word == lemma.lemma_form) {

           outFile << lemma.lemma_id << '|' << line2 << '|' << lemma.lemma_form << '|' << Dejotate(lemma.morph_replace) << '|' << '|' << lemma.poss_doublet << '|' << lemma.loan_place << '|'  << lemma.long_adj << '|' << boolToStr(lemma.non_assim) << '|' << lemma.eng_trans << '|' << '|' << lemma.etym_disc << '|' << lemma.bad_etym << '|' << lemma.loan_source << '|' << '|' << '|' << lemma.conj_type << '|' << '|' << '|' << std::endl;
             }
  else { outFile <<  lemma.lemma_id << '|' << line2 << '|' << dejotated_word << '|' << Dejotate(lemma.morph_replace) << '|' << '|' << lemma.poss_doublet << '|' << lemma.loan_place << '|' << lemma.long_adj << '|' << boolToStr(lemma.non_assim) << '|' << lemma.eng_trans << '|' << lemma.lemma_form << '|' << lemma.etym_disc << '|' << lemma.bad_etym << '|' << lemma.loan_source << '|' << '|' << '|' << lemma.conj_type << '|' << '|' << '|' << std::endl;}
}

else {  std::getline(inFile2, line2);

outFile << '|' << line2 << '|' << '|' << '|' << '|' << '|' << '|' << '|' << '|' << '|' << '|' << '|' << '|' << '|' << '|' << '|' << '|' << '|' << '|' << '|' << '|' << '|' << '|' << std::endl;
  }
  row.clear();
}

outFile.close();
inFile.close();
inFile2.close();
}





int main() {

    std::string filename;

    std::cout << "Enter filename (including the .csv): ";
    std::cin >> filename;

    bool fileExists = addDummyrow(filename);
      if(fileExists == false) { std::cout << "No such file in directory" << std::endl; return 0; }
    int form_pos = form_col_no("dummyrow.csv");
      if(form_pos == 999) { std::remove("dummyrow.csv"); return 0; }
    int lemma_id_pos = lemma_id_col_no("dummyrow.csv");
      if(lemma_id_pos == 999) { std::remove("dummyrow.csv"); return 0; }
    int morphology_pos =  morphology_col_no("dummyrow.csv");
      if(morphology_pos == 999) { std::remove("dummyrow.csv"); return 0; }
    std::string filename2 = str_Truncate(filename, 4) + "_autoreconstructed_temp.csv";
    std::string filename3 = str_Truncate(filename, 4) + "_autoreconstructed.csv";

    std::cout << "Cleaning, deep-cleaning and Glagoliticising TOROT text...";
    createBasefiles(filename2, form_pos, lemma_id_pos, morphology_pos);
    std::remove("dummyrow.csv");
    std::cout << std::endl << "Reconstructing..." << std::endl;
    Reconstruct("deep_cleaned.csv", filename2, filename3);
    const char* file_name_temp = filename2.c_str();
    std::remove(file_name_temp);




  return 0;
}
