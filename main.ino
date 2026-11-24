/* näide praksitunni jaoks. päris koodi tahaks ise teha ja veits rohekm aega võtta selleks, niiet siin lihtne simu
autor:Tuuli Leuke
kuupäev:24.11.2026*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

int main() {
    srand(time(0));

    int score = 0;
    int mistakes = 0;
    int targetButton = 0;

    int totalReactionTime = 0;
    int bestReactionTime = 0;

    const int GAME_TIME = 60;

    cout << "==========================" << endl;
    cout << "    REACTION TIME GAME    " << endl;
    cout << "==========================" << endl;

    cout << "Press ENTER to start...";
    cin.get();

    cout << "\nGet ready!" << endl;

    for (int i = 3; i > 0; i--) {
        cout << i << "..." << endl;
    }

    cout << "\nGAME STARTED!" << endl;

    auto gameStart = chrono::steady_clock::now();

    while (chrono::duration_cast<chrono::seconds>(
        chrono::steady_clock::now() - gameStart
    ).count() < GAME_TIME) {

        // Select random button
        targetButton = rand() % 4 + 1;

        cout << "\nPress button " << targetButton << "!" << endl;

        auto reactionStart = chrono::steady_clock::now();

        int pressedButton;
        cin >> pressedButton;

        auto reactionEnd = chrono::steady_clock::now();

        int reactionTime =
            chrono::duration_cast<chrono::milliseconds>(
                reactionEnd - reactionStart
            ).count();

        // Check player input
        if (pressedButton == targetButton) {

            score++;
            totalReactionTime += reactionTime;

            if (bestReactionTime == 0 ||
                reactionTime < bestReactionTime) {
                bestReactionTime = reactionTime;
            }

            cout << "Correct! Reaction time: "
                 << reactionTime << " ms" << endl;

        } else {

            mistakes++;
            cout << "Wrong button!" << endl;
        }

        cout << "Score: " << score
             << " | Mistakes: " << mistakes << endl;
    }

    // Calculate average reaction time
    int averageReactionTime = 0;

    if (score > 0) {
        averageReactionTime = totalReactionTime / score;
    }

    // Display results
    cout << "\n==========================" << endl;
    cout << "       GAME FINISHED      " << endl;
    cout << "==========================" << endl;

    cout << "Final score: " << score << endl;
    cout << "Average reaction time: "
         << averageReactionTime << " ms" << endl;
    cout << "Best reaction time: "
         << bestReactionTime << " ms" << endl;
    cout << "Mistakes: " << mistakes << endl;

    return 0;
}
