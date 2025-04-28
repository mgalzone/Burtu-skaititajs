#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <map>

using namespace std;

void sajauktievardi() {
    const int a = 10;
    string vards[a] = {
        "banquet",
        "whistle",
        "journey",
        "fragile",
        "velvet",
        "harvest",
        "adventure",
        "glimpse",
        "satisfaction",
        "sincere"
    };

    string nvards[a] = {
        "baqtune",
        "whleist",
        "eynjrou",
        "glfraei",
        "tvveel",
        "tsrahve",
        "advurtnee",
        "pscmilge",
        "saftcinatiso",
        "eernisc"
    };

    string j;
    int score = 0;

    cout << "Sakaarto burtus pareizaa seciibaa!" << endl;

    for(int i = 0; i < a; i++)
    {
        cout << "\nSajauktais vards: " << nvards[i] << endl;
        cin >> j;
        if(j == vards[i])
        {
            cout << "Apsveicu!" << endl;
            score++;
        }
        else
        {
            cout << "Nepareizi. Pareizaa atbilde: " << vards[i] << endl;
        }
    }

    cout << "\nTavs rezultaats: " << score << " no " << a << " pareiziem." << endl;
}

// spele ar patskanu un lidzskanu minesanu
void pirmaaspele() {
    string teikums;
    cout << "Spele: straadaa ar savu teikumu" << endl;
    cout << "Ievadi garu teikumu: ";
    getline(cin, teikums);

    int patskani = 0, lidzskani = 0;

    for (char burts : teikums) {
        if (isalpha(burts)) {
            if (burts == 'a' || burts == 'e' || burts == 'i' || burts == 'o' || burts == 'u' ||
                burts == 'A' || burts == 'E' || burts == 'I' || burts == 'O' || burts == 'U') {
                ++patskani;
            } else {
                ++lidzskani;
            }
        }
    }

    int minetiepatskani, minetielidzskani;
    cout << "Uzmini, cik patskanu ir teikumaa: ";
    cin >> minetiepatskani;
    cout << "Uzmini, cik lidzskanu ir teikumaa: ";
    cin >> minetielidzskani;
    cin.ignore();

    if (minetiepatskani == patskani && minetielidzskani == lidzskani)
        cout << "Mineejums ir pareizs!" << endl;
    else {
        cout << "Nepareizi." << endl;
        cout << "Pareizi: " << patskani << " patskani un " << lidzskani << " lidzskani." << endl;
    }
}

void skaidrojums(int indekss) {
    vector<string> paskaidrojumi = {
        "*would* nevar izmantot *if* dalaa",
        "*which* nevar izmantot, kad runa par cilvekiem – jalieto *who*",
        "ar vardu *married* jaizmanto *to*, nevis *with*",
        "ja pat *team* norada, ka tajaa ir vairaki cilveki, jaiznoto *is*, jo *team* ir tikai viena",
        "nepareiza pagatnes forma, pec *has* jaalieto *gone*, nevis *went*",
        "nepareiza vardu seciba – ja butu tikai *what time is it?*, tad butu pareizi",
        "taa nedrikst, jo sanak *double negatives* viena teikumaa",
        "*their* jaizmanto citaa nozimee – jasaka *they are* jeb *they’re*",
        "iespejamas situacijas, jaiznoto *were*, nevis *was*",
        "atkartotam darbibaam jaiznoto *present perfect* - *has sung*, nevis *sang*",
        "*its* sajaa teikumaa ir nozime *it is*, tapec saisinajumaa tas butu *it’s*",
        "nedrikst lietot *more* pirms *kinder*, jo *kinder* jau ir paraakaa forma",
        "*whom* jaiznoto citaa nozimee",
        "*each* noraada, ka jaizmanto vards vienskaitli (*has*), ja pat vinu ir vairak",
        "*suggested me* – pec *suggested* lieto *that I go*, nevis *me*",
        "*less people* – ja runa par saskaitamiem lietvardiem, jasaka *fewer*",
        "*borrow me* nav pareizi – ja ir vajadziba kaut ko sanemt, lieto *lend*",
        "*used to* lieto citaa nozimee",
        "*environment* raksta ar *n*",
        "*acquaintances* raksta ar *a*"
    };
    cout << "Paskaidrojums: " << paskaidrojumi[indekss] << endl;
}

void kludas() {
    vector<string> kludaini = {
        "If I would have known, I would have helped.",
        "The man which helped you is my brother.",
        "She is married with a lawyer.",
        "The team are winning the match.",
        "He has went to the store.",
        "Do you know what time is it?",
        "I don’t know nothing.",
        "Their going to the concert tonight.",
        "If I was you, I wouldn’t do that.",
        "She sang that song many times before.",
        "Its a beautiful day outside.",
        "She was more kinder than before.",
        "Whom is knocking at the door?",
        "Each of the students have a book.",
        "He suggested me to go there.",
        "There are less people at the event.",
        "Can you borrow me your pen?",
        "I didn't used to like coffee.",
        "He seems to like this enviroment.",
        "She has many acquaintences."
    };

    vector<string> pareizie = {
        "If I had known, I would have helped.",
        "The man who helped you is my brother.",
        "She is married to a lawyer.",
        "The team is winning the match.",
        "He has gone to the store.",
        "Do you know what time it is?",
        "I don’t know anything.",
        "They’re going to the concert tonight.",
        "If I were you, I wouldn’t do that.",
        "She has sung that song many times before.",
        "It's a beautiful day outside.",
        "She was kinder than before.",
        "Who is knocking at the door?",
        "Each of the students has a book.",
        "He suggested that I go there.",
        "There are fewer people at the event.",
        "Can you lend me your pen?",
        "I didn't use to like coffee.",
        "He seems to like this environment.",
        "She has many acquaintances."
    };

    int score = 0;

    for (int i = 0; i < kludaini.size(); ++i) {
        string atbilde;
        cout << "\nAtrodi kludu saja teikumaa (ievadi laboto versiju):\n";
        cout << "-> Teikums: " << kludaini[i] << endl;
        cout << "Izlabotais teikums: ";
        getline(cin, atbilde);
        if (atbilde == pareizie[i]) {
            cout << "Pareizi!\n";
            ++score;
        } else {
            cout << "Nepareizi – pareizais teikums ir:\n";
            cout << "\"" << pareizie[i] << "\"\n";
            skaidrojums(i);
        }
    }

    cout << "\nTu pareizi atbildeji uz " << score << " no " << kludaini.size() << " jautajumiem.\n";
}

int main() {
    vector<int> patskanuskaits;
    vector<int> lidzskanuskaits;
    vector<int> kopaburti;

    string teikums;
    cout << "Ievads: ievadi garaku tekstu, kam velies noteikt patskanu, lidzskanu skaitu u.c.: ";
    getline(cin, teikums);

    int patskani = 0, lidzskani = 0, atstarpes = 0;

    for (int i = 0; i < teikums.length(); ++i) {
        char burts = teikums[i];
        if (burts == 'a' || burts == 'e' || burts == 'i' || burts == 'o' || burts == 'u' ||
            burts == 'A' || burts == 'E' || burts == 'I' || burts == 'O' || burts == 'U') {
            ++patskani;
        } else if (isalpha(burts)) {
            ++lidzskani;
        } else if (burts == ' ') {
            ++atstarpes;
        }
    }

    patskanuskaits.push_back(patskani);
    lidzskanuskaits.push_back(lidzskani);
    kopaburti.push_back(patskani + lidzskani);

    cout << "Patskani: " << patskani << endl;
    cout << "Lidzskani: " << lidzskani << endl;
    cout << "Burti kopaa: " << (patskani + lidzskani) << endl;
    cout << "Atstarpes: " << atstarpes << endl;

    map<char, int> burtiCount;
    for (char c : teikums) {
        if (isalpha(c)) {
            burtiCount[tolower(c)]++;
        }
    }

    char visbiezakaisburts;
int burtuskaits = 0;
for (auto& b : burtiCount) {
    if (b.second > burtuskaits) {
        burtuskaits = b.second;
        visbiezakaisburts = b.first;
    }
}
cout << "Visbiezak lietotais burts: '" << visbiezakaisburts << "' - " << burtuskaits << " reizes.\n";


    vector<pair<char, int>> sakartotiBurti(burtiCount.begin(), burtiCount.end());
    sort(sakartotiBurti.begin(), sakartotiBurti.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
        return b.second < a.second ? false : (b.second == a.second ? a.first < b.first : true);
    });

    cout << "\nBurtu lietojuma statistika (no visbiezak lidz visretak):\n";
    for (const auto& par : sakartotiBurti) {
        cout << "'" << par.first << "' - " << par.second << " reizes\n";
    }

    pirmaaspele();
    kludas();
    sajauktievardi();

    return 0;
}
