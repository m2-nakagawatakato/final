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
        cout << "ファイルが開けませんでした。" << endl;
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
        cout << "ハイスコアが見つかりません。" << endl;
        return;
    }

    vector<int> scores1;
    int score1;
    while (infile >> score1) {
        scores1.push_back(score1);
    }
    infile.close();

    sort(scores1.begin(), scores1.end(), greater<int>());
    cout << "ハイスコアランキング:" << endl;
    for (size_t i = 0; i < min(scores1.size(), size_t(10)); ++i) {
        cout << (i + 1) << "位: " << scores1[i] << "点" << endl;
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
        cout << "ハイスコアが見つかりません。" << endl;
        return;
    }

    vector<int> scores2;
    int score2;
    while (infile >> score2) {
        scores2.push_back(score2);
    }
    infile.close();

    sort(scores2.begin(), scores2.end(), greater<int>());
    cout << "ハイスコアランキング:" << endl;
    for (size_t i = 0; i < min(scores2.size(), size_t(10)); ++i) {
        cout << (i + 1) << "位: " << scores2[i] << "点" << endl;
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
        cout << "ハイスコアが見つかりません。" << endl;
        return;
    }

    vector<int> scores3;
    int score3;
    while (infile >> score3) {
        scores3.push_back(score3);
    }
    infile.close();

    sort(scores3.begin(), scores3.end(), greater<int>());
    cout << "ハイスコアランキング:" << endl;
    for (size_t i = 0; i < min(scores3.size(), size_t(10)); ++i) {
        cout << (i + 1) << "位: " << scores3[i] << "点" << endl;
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
        cout << "ハイスコアが見つかりません。" << endl;
        return;
    }

    vector<int> scores4;
    int score4;
    while (infile >> score4) {
        scores4.push_back(score4);
    }
    infile.close();

    sort(scores4.begin(), scores4.end(), greater<int>());
    cout << "ハイスコアランキング:" << endl;
    for (size_t i = 0; i < min(scores4.size(), size_t(10)); ++i) {
        cout << (i + 1) << "位: " << scores4[i] << "点" << endl;
    }
}

void onecharacter() {
    vector<string> gojyuu = {
        "あ", "い", "う", "え", "お",
        "か", "き", "く", "け", "こ",
        "さ", "し", "す", "せ", "そ",
        "た", "ち", "つ", "て", "と",
        "な", "に", "ぬ", "ね", "の",
        "は", "ひ", "ふ", "へ", "ほ",
        "ま", "み", "む", "め", "も",
        "や", "ゆ", "よ",
        "ら", "り", "る", "れ", "ろ",
        "わ", "を", "ん"
    };
    srand(static_cast<unsigned int>(time(0)));

    printf("全角にして表示される文字を入力してください。\n");
    clock_t start = clock();
    int result = 0;
    for (int i = 0; i < T; ++i) {
        int index = rand() % gojyuu.size();
        vector<string>::iterator it = gojyuu.begin();
        advance(it, index);
        cout << (i + 1) << "文字目" << ":" << *it << ":";
        string input;
        getline(cin, input);
        if (input == *it)
            ++result;
    }
    clock_t end = clock();
    int score1 = result * 10 - (end - start) / CLOCKS_PER_SEC;  
    printf(" %d 問中 %d 問正解しました。\n", T, result);
    cout << "スコア: " << score1 << "点\n";
    saveHighscore1(score1);
    cout << "タイム" << (double)(end - start) / CLOCKS_PER_SEC << "秒\n";
}

void typing1() {
    vector<Question> Questions = vecQuestion();

    printf("全角にして表示される文章を入力してください。\n");
    clock_t start = clock();
    int result = 0;
    for (int i = 0; i < T; ++i) {
        const int n = rand() % Questions.size();
        const string& word1 = Questions[n].getWord1();
        printf("%d 個目：%s:", i + 1, word1.c_str());
        char input[256];
        if (scanf("%255s", input) == 1) {
            if (word1 == input)
                ++result;
        }
        else {
            printf("入力失敗!\n");
            exit(1);
        }
    }
    clock_t end = clock();
    int score2 = result * 10 - (end - start) / CLOCKS_PER_SEC; 
    printf(" %d 問中 %d 問正解しました。\n", T, result);
    cout << "スコア: " << score2 << "点\n";
    saveHighscore2(score2);
    cout << "タイム" << (double)(end - start) / CLOCKS_PER_SEC << "秒\n";
}

void typing2() {
    vector<Question> Questions = vecQuestion();

    printf("全角にして表示される文章を入力してください。\n");
    clock_t start = clock();
    int result = 0;
    for (int i = 0; i < T; ++i) {
        const int n = rand() % Questions.size();
        const string& word2 = Questions[n].getWord2();
        printf("%d 個目：%s:", i + 1, word2.c_str());
        char input[256];
        if (scanf("%255s", input) == 1) {
            if (word2 == input)
                ++result;
        }
        else {
            printf("入力失敗!\n");
            exit(1);
        }
    }
    clock_t end = clock();
    int score3 = result * 50 - (end - start) / CLOCKS_PER_SEC;
    printf(" %d 問中 %d 問正解しました。\n", T, result);
    cout << "スコア: " << score3 << "点\n";
    saveHighscore3(score3);
    cout << "タイム" << (double)(end - start) / CLOCKS_PER_SEC << "秒\n";
}

void typing3() {
    vector<Question> Questions = vecQuestion();

    printf("全角にして表示される文章を入力してください。\n");
    clock_t start = clock();
    int result = 0;
    for (int i = 0; i < T; ++i) {
        const int n = rand() % Questions.size();
        const string& word3 = Questions[n].getWord3();
        printf("%d 個目：%s:", i + 1, word3.c_str());
        char input[256];
        if (scanf("%255s", input) == 1) {
            if (word3 == input)
                ++result;
        }
        else {
            printf("入力失敗!\n");
            exit(1);
        }
    }
    clock_t end = clock();
    int score4 = result * 100 - (end - start) / CLOCKS_PER_SEC;
    printf(" %d 問中 %d 問正解しました。\n", T, result);
    cout << "スコア: " << score4 << "点\n";
    saveHighscore4(score4);
    cout << "タイム" << (double)(end - start) / CLOCKS_PER_SEC << "秒\n";
}

int main() {
    srand(static_cast<unsigned int>(time(NULL)));

    ofstream outfile("final.txt", ios_base::out);
    if (!outfile) {
        cout << "ファイルが開けませんでした。" << endl;
        exit(1);
    }
    outfile << "りんご" << endl << "こしたんたん" << endl << "機械システム工学科" << endl;
    outfile << "ねこ" << endl << "ゆいがどくそん" << endl << "東京都八王子市南大沢" << endl;
    outfile << "さんま" << endl << "おんこちしん" << endl << "首都大学東京" << endl;
    outfile << "いぬ" << endl << "ふうりんかざん" << endl << "東京都立大学" << endl;
    outfile << "きりん" << endl << "いんがおうほう" << endl << "隣の客はよく柿食う客だ" << endl;
    outfile << "かめ" << endl << "ちみもうりょう" << endl << "プログラミングを頑張るぞ！" << endl;
    outfile << "いちご" << endl << "しめんそか" << endl << "プログラミングって難しい" << endl;
    outfile << "わたあめ" << endl << "がりょうてんせい" << endl << "インスタグラムに投稿する" << endl;
    outfile << "れもん" << endl << "いちごいちえ" << endl << "過去の自分が今僕の土台となる" << endl;
    outfile << "あめ" << endl << "しんらばんしょう" << endl << "諦めたらそこで試合終了ですよ" << endl;
    outfile << "ぶどう" << endl << "しょぎょうむじょう" << endl << "人事を尽くして天命を待つ" << endl;
    outfile << "ガム" << endl << "かちょうふうげつ" << endl << "寝違えて首が痛い" << endl;
    outfile << "パソコン" << endl << "あびきょうかん" << endl << "敵は己の中にあり" << endl;
    outfile << "ねずみ" << endl << "ほんまつてんとう" << endl << "新聞紙，逆から読んでも新聞紙" << endl;
    outfile << "ぞう" << endl << "せっさたくま" << endl << "トイレに駆け込む" << endl;
    outfile << "ライオン" << endl << "いっちょういっせき" << endl << "布団が吹っ飛んだ" << endl;
    outfile << "カモノハシ" << endl << "まんしんそうい" << endl << "失敗は成功のもと" << endl;
    outfile << "にわとり" << endl << "ひゃっかりょうらん" << endl << "月がきれいですね" << endl;
    outfile << "なっとう" << endl << "てんしんらんまん" << endl << "意志あるところに道は開ける" << endl;
    outfile << "うし" << endl << "がしんしょうたん" << endl << "強い者が勝つのではない，勝ったものが強いのだ" << endl;
    outfile.close();

    printf("タイピングゲーム!\nゲームの種類を選択\n１：一文字入力　２：文章入力　３：ハイスコア表示(一文字入力)　4：ハイスコア表示(初級)　5：ハイスコア表示(中級)　6：ハイスコア表示(上級)\n");
    switch (getchar()) {
    case '1':
        getchar();
        onecharacter();
        break;
    case '2':
        getchar();

        printf("難易度を選択\n1：初級、2：中級，3：上級\n");
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
        printf("選択肢にありません。\n");
        break;
    }


    return 0;
}
