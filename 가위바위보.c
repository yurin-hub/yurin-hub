#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

void delay(int seconds) {
    #ifdef _WIN32
    Sleep(seconds * 1000);
    #else
    sleep(seconds);
    #endif
}

int main() {
    int userChoice, computerChoice, score = 0;
    const char *choices[] = {"가위", "바위", "보"};
    char playAgain;

    srand(time(NULL));

    do {
        do {
            printf("0: 가위, 1: 바위, 2: 보\n선택하세요: "); 
            scanf("%d", &userChoice);
        } while (userChoice < 0 || userChoice > 2);

        printf("결과를 계산 중입니다...\n");
        delay(2);
        
        computerChoice = rand() % 3;
        printf("당신: %s, 컴퓨터: %s\n", choices[userChoice], choices[computerChoice]);
        
        if (userChoice == computerChoice) {
            printf("결과: 무승부!\n");
        } else if ((userChoice + 1) % 3 == computerChoice) {
            printf("결과: 패배!\n");
        } else {
            printf("결과: 승리!\n");
            score++;
        }
        
        printf("현재 점수: %d\n", score);
        printf("한 번 더 하시겠습니까? (y/n): ");
        scanf(" %c", &playAgain);
        
    } while (playAgain == 'y' || playAgain == 'Y');

    printf("게임 종료! 최종 점수: %d\n", score);
    return 0;
}
