#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <fstream>
#include <vector>
#include <limits>

int T = 10;  
using namespace std;

class Question {
    string word1;
    string word2;
    string word3;
public:
    Question() : word1(""), word2(""), word3("") {}
    Question(const string& newWord1, const string& newWord2, const string& newWord3)
        : word1(newWord1), word2(newWord2), word3(newWord3) {}
    void setWord1(const string& newWord1) { word1 = newWord1; }
    void setWord2(const string& newWord2) { word2 = newWord2; }
    void setWord3(const string& newWord3) { word3 = newWord3; }
    string getWord1() const { return word1; }
    string getWord2() const { return word2; }
    string getWord3() const { return word3; }
};

vector<Question> vecQuestion() {
    ifstream infile("final.txt");
    if (!infile) {
        cout << "�t�@�C�����J���܂���ł����B" << endl;
        exit(1);
    }

    string word1, word2, word3;
    vector<Question> Questions;
    while (getline(infile, word1) && getline(infile, word2) && getline(infile, word3)) {
        Questions.push_back(Question(word1, word2, word3));
    }
    infile.close();
    return Questions;
}

void print(const vector<Question>& Questions) {
    for (const auto& Question : Questions) {
        cout << Question.getWord1() << " " << Question.getWord2() << " " << Question.getWord3() << endl;
    }
}

void saveHighscore1(int score1) {
    ofstream outfile("score.txt", ios_base::app);
    if (outfile) {
        outfile << score1 << endl;
        outfile.close();
    }
}

void displayHighscores1() {
    ifstream infile("score.txt");
    if (!infile) {
        cout << "�n�C�X�R�A��������܂���B" << endl;
        return;
    }

    vector<int> scores1;
    int score1;
    while (infile >> score1) {
        scores1.push_back(score1);
    }
    infile.close();

    sort(scores1.begin(), scores1.end(), greater<int>());
    cout << "�n�C�X�R�A�����L���O:" << endl;
    for (size_t i = 0; i < min(scores1.size(), size_t(10)); ++i) {
        cout << (i + 1) << "��: " << scores1[i] << "�_" << endl;
    }
}

void saveHighscore2(int score2) {
    ofstream outfile("score2.txt", ios_base::app);
    if (outfile) {
        outfile << score2 << endl;
        outfile.close();
    }
}

void displayHighscores2() {
    ifstream infile("score2.txt");
    if (!infile) {
        cout << "�n�C�X�R�A��������܂���B" << endl;
        return;
    }

    vector<int> scores2;
    int score2;
    while (infile >> score2) {
        scores2.push_back(score2);
    }
    infile.close();

    sort(scores2.begin(), scores2.end(), greater<int>());
    cout << "�n�C�X�R�A�����L���O:" << endl;
    for (size_t i = 0; i < min(scores2.size(), size_t(10)); ++i) {
        cout << (i + 1) << "��: " << scores2[i] << "�_" << endl;
    }
}

void saveHighscore3(int score3) {
    ofstream outfile("score3.txt", ios_base::app);
    if (outfile) {
        outfile << score3 << endl;
        outfile.close();
    }
}

void displayHighscores3() {
    ifstream infile("score3.txt");
    if (!infile) {
        cout << "�n�C�X�R�A��������܂���B" << endl;
        return;
    }

    vector<int> scores3;
    int score3;
    while (infile >> score3) {
        scores3.push_back(score3);
    }
    infile.close();

    sort(scores3.begin(), scores3.end(), greater<int>());
    cout << "�n�C�X�R�A�����L���O:" << endl;
    for (size_t i = 0; i < min(scores3.size(), size_t(10)); ++i) {
        cout << (i + 1) << "��: " << scores3[i] << "�_" << endl;
    }
}

void saveHighscore4(int score4) {
    ofstream outfile("score4.txt", ios_base::app);
    if (outfile) {
        outfile << score4 << endl;
        outfile.close();
    }
}

void displayHighscores4() {
    ifstream infile("score4.txt");
    if (!infile) {
        cout << "�n�C�X�R�A��������܂���B" << endl;
        return;
    }

    vector<int> scores4;
    int score4;
    while (infile >> score4) {
        scores4.push_back(score4);
    }
    infile.close();

    sort(scores4.begin(), scores4.end(), greater<int>());
    cout << "�n�C�X�R�A�����L���O:" << endl;
    for (size_t i = 0; i < min(scores4.size(), size_t(10)); ++i) {
        cout << (i + 1) << "��: " << scores4[i] << "�_" << endl;
    }
}

void onecharacter() {
    vector<string> gojyuu = {
        "��", "��", "��", "��", "��",
        "��", "��", "��", "��", "��",
        "��", "��", "��", "��", "��",
        "��", "��", "��", "��", "��",
        "��", "��", "��", "��", "��",
        "��", "��", "��", "��", "��",
        "��", "��", "��", "��", "��",
        "��", "��", "��",
        "��", "��", "��", "��", "��",
        "��", "��", "��"
    };
    srand(static_cast<unsigned int>(time(0)));

    printf("�S�p�ɂ��ĕ\������镶������͂��Ă��������B\n");
    clock_t start = clock();
    int result = 0;
    for (int i = 0; i < T; ++i) {
        int index = rand() % gojyuu.size();
        vector<string>::iterator it = gojyuu.begin();
        advance(it, index);
        cout << (i + 1) << "������" << ":" << *it << ":";
        string input;
        getline(cin, input);
        if (input == *it)
            ++result;
    }
    clock_t end = clock();
    int score1 = result * 10 - (end - start) / CLOCKS_PER_SEC;  
    printf(" %d �⒆ %d �␳�����܂����B\n", T, result);
    cout << "�X�R�A: " << score1 << "�_\n";
    saveHighscore1(score1);
    cout << "�^�C��" << (double)(end - start) / CLOCKS_PER_SEC << "�b\n";
}

void typing1() {
    vector<Question> Questions = vecQuestion();

    printf("�S�p�ɂ��ĕ\������镶�͂���͂��Ă��������B\n");
    clock_t start = clock();
    int result = 0;
    for (int i = 0; i < T; ++i) {
        const int n = rand() % Questions.size();
        const string& word1 = Questions[n].getWord1();
        printf("%d �ځF%s:", i + 1, word1.c_str());
        char input[256];
        if (scanf("%255s", input) == 1) {
            if (word1 == input)
                ++result;
        }
        else {
            printf("���͎��s!\n");
            exit(1);
        }
    }
    clock_t end = clock();
    int score2 = result * 10 - (end - start) / CLOCKS_PER_SEC; 
    printf(" %d �⒆ %d �␳�����܂����B\n", T, result);
    cout << "�X�R�A: " << score2 << "�_\n";
    saveHighscore2(score2);
    cout << "�^�C��" << (double)(end - start) / CLOCKS_PER_SEC << "�b\n";
}

void typing2() {
    vector<Question> Questions = vecQuestion();

    printf("�S�p�ɂ��ĕ\������镶�͂���͂��Ă��������B\n");
    clock_t start = clock();
    int result = 0;
    for (int i = 0; i < T; ++i) {
        const int n = rand() % Questions.size();
        const string& word2 = Questions[n].getWord2();
        printf("%d �ځF%s:", i + 1, word2.c_str());
        char input[256];
        if (scanf("%255s", input) == 1) {
            if (word2 == input)
                ++result;
        }
        else {
            printf("���͎��s!\n");
            exit(1);
        }
    }
    clock_t end = clock();
    int score3 = result * 50 - (end - start) / CLOCKS_PER_SEC;
    printf(" %d �⒆ %d �␳�����܂����B\n", T, result);
    cout << "�X�R�A: " << score3 << "�_\n";
    saveHighscore3(score3);
    cout << "�^�C��" << (double)(end - start) / CLOCKS_PER_SEC << "�b\n";
}

void typing3() {
    vector<Question> Questions = vecQuestion();

    printf("�S�p�ɂ��ĕ\������镶�͂���͂��Ă��������B\n");
    clock_t start = clock();
    int result = 0;
    for (int i = 0; i < T; ++i) {
        const int n = rand() % Questions.size();
        const string& word3 = Questions[n].getWord3();
        printf("%d �ځF%s:", i + 1, word3.c_str());
        char input[256];
        if (scanf("%255s", input) == 1) {
            if (word3 == input)
                ++result;
        }
        else {
            printf("���͎��s!\n");
            exit(1);
        }
    }
    clock_t end = clock();
    int score4 = result * 100 - (end - start) / CLOCKS_PER_SEC;
    printf(" %d �⒆ %d �␳�����܂����B\n", T, result);
    cout << "�X�R�A: " << score4 << "�_\n";
    saveHighscore4(score4);
    cout << "�^�C��" << (double)(end - start) / CLOCKS_PER_SEC << "�b\n";
}

int main() {
    srand(static_cast<unsigned int>(time(NULL)));

    ofstream outfile("final.txt", ios_base::out);
    if (!outfile) {
        cout << "�t�@�C�����J���܂���ł����B" << endl;
        exit(1);
    }
    outfile << "���" << endl << "�������񂽂�" << endl << "�@�B�V�X�e���H�w��" << endl;
    outfile << "�˂�" << endl << "�䂢���ǂ�����" << endl << "�����s�����q�s����" << endl;
    outfile << "�����" << endl << "���񂱂�����" << endl << "��s��w����" << endl;
    outfile << "����" << endl << "�ӂ���񂩂���" << endl << "�����s����w" << endl;
    outfile << "�����" << endl << "���񂪂����ق�" << endl << "�ׂ̋q�͂悭�`�H���q��" << endl;
    outfile << "����" << endl << "���݂�����傤" << endl << "�v���O���~���O���撣�邼�I" << endl;
    outfile << "������" << endl << "���߂񂻂�" << endl << "�v���O���~���O���ē��" << endl;
    outfile << "�킽����" << endl << "����傤�Ă񂹂�" << endl << "�C���X�^�O�����ɓ��e����" << endl;
    outfile << "�����" << endl << "������������" << endl << "�ߋ��̎��������l�̓y��ƂȂ�" << endl;
    outfile << "����" << endl << "�����΂񂵂傤" << endl << "���߂��炻���Ŏ����I���ł���" << endl;
    outfile << "�Ԃǂ�" << endl << "���催�傤�ނ��傤" << endl << "�l����s�����ēV����҂�" << endl;
    outfile << "�K��" << endl << "�����傤�ӂ�����" << endl << "�Q�Ⴆ�Ď񂪒ɂ�" << endl;
    outfile << "�p�\�R��" << endl << "���т��傤����" << endl << "�G�͌Ȃ̒��ɂ���" << endl;
    outfile << "�˂���" << endl << "�ق�܂Ă�Ƃ�" << endl << "�V�����C�t����ǂ�ł��V����" << endl;
    outfile << "����" << endl << "������������" << endl << "�g�C���ɋ삯����" << endl;
    outfile << "���C�I��" << endl << "�������傤��������" << endl << "�z�c���������" << endl;
    outfile << "�J���m�n�V" << endl << "�܂񂵂񂻂���" << endl << "���s�͐����̂���" << endl;
    outfile << "�ɂ�Ƃ�" << endl << "�Ђ������傤���" << endl << "�������ꂢ�ł���" << endl;
    outfile << "�Ȃ��Ƃ�" << endl << "�Ă񂵂���܂�" << endl << "�ӎu����Ƃ���ɓ��͊J����" << endl;
    outfile << "����" << endl << "�����񂵂傤����" << endl << "�����҂����̂ł͂Ȃ��C���������̂������̂�" << endl;
    outfile.close();

    printf("�^�C�s���O�Q�[��!\n�Q�[���̎�ނ�I��\n�P�F�ꕶ�����́@�Q�F���͓��́@�R�F�n�C�X�R�A�\��(�ꕶ������)�@4�F�n�C�X�R�A�\��(����)�@5�F�n�C�X�R�A�\��(����)�@6�F�n�C�X�R�A�\��(�㋉)\n");
    switch (getchar()) {
    case '1':
        getchar();
        onecharacter();
        break;
    case '2':
        getchar();

        printf("��Փx��I��\n1�F�����A2�F�����C3�F�㋉\n");
        switch (getchar()) {
        case '1':
            getchar();
            typing1();
            break;
        case '2':
            getchar();
            typing2();
            break;
        case '3':
            getchar();
            typing3();
            break;
        default:
            break;
        }

        break;
    case '3':
        getchar();
        displayHighscores1();
        break;
    case '4':
        getchar();
        displayHighscores2();
        break;
    case '5':
        getchar();
        displayHighscores3();
        break;
    case '6':
        getchar();
        displayHighscores4();
        break;
    default:
        printf("�I�����ɂ���܂���B\n");
        break;
    }


    return 0;
}
