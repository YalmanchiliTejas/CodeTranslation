#include <iostream>
#include <string.h>

struct dotsOfDice
{
    unsigned int top;
    unsigned int bottom;
    unsigned int north;
    unsigned int east;
    unsigned int south;
    unsigned int west;
};

class Dice
{
public:
    
    Dice()          /* constructor */
    {
        memset(&dots, 0, sizeof(dots));
    }
    ~Dice(){};        /* destructor */
    
    void initialize(void);
    
    unsigned int getTop(void);
    
    void roll(std::string* order);
    
private:
    
    dotsOfDice dots;
    
    std::string north = "North";
    std::string east  = "East";
    std::string south = "South";
    std::string west  = "West";
    std::string right = "Right";
    std::string left  = "Left";
    
    void rollNorth(void);
    void rollEast(void);
    void rollSouth(void);
    void rollWest(void);
    void rollRight(void);
    void rollLeft(void);
    void swapDots(unsigned int*, unsigned int*);
    
    /* Debug */
    void checkDots(void);
    void showDots(void);
    
};

void Dice::initialize(void)
{
    dots.top    = 1;
    dots.bottom = 6;
    dots.north  = 5;
    dots.east   = 3;
    dots.south  = 2;
    dots.west   = 4;
}

unsigned int Dice::getTop(void)
{
    return dots.top;
}

void Dice::roll(std::string* pOrder)
{
    if(*pOrder == north)
    {
        rollNorth();
    }
    else if(*pOrder == east)
    {
        rollEast();
    }
    else if(*pOrder == south)
    {
        rollSouth();
    }
    else if(*pOrder == west)
    {
        rollWest();
    }
    else if(*pOrder == right)
    {
        rollRight();
    }
    else if(*pOrder == left)
    {
        rollLeft();
    }
    else
    {
        /* Do nothing */
    }
    return;
}

void Dice::rollNorth(void)
{
    swapDots(&dots.bottom, &dots.north);
    swapDots(&dots.north, &dots.top);
    swapDots(&dots.top, &dots.south);
    return;
}
void Dice::rollEast(void)
{
    swapDots(&dots.bottom, &dots.east);
    swapDots(&dots.east, &dots.top);
    swapDots(&dots.top, &dots.west);
    return;
}
void Dice::rollSouth(void)
{
    swapDots(&dots.bottom, &dots.south);
    swapDots(&dots.south, &dots.top);
    swapDots(&dots.top, &dots.north);
    return;
}
void Dice::rollWest(void)
{
    swapDots(&dots.bottom, &dots.west);
    swapDots(&dots.west, &dots.top);
    swapDots(&dots.top, &dots.east);
    return;
}
void Dice::rollRight(void)
{
    swapDots(&dots.north, &dots.west);
    swapDots(&dots.west, &dots.south);
    swapDots(&dots.south, &dots.east);
    return;
}
void Dice::rollLeft(void)
{
    swapDots(&dots.north, &dots.east);
    swapDots(&dots.east, &dots.south);
    swapDots(&dots.south, &dots.west);
    return;
}

void Dice::swapDots(unsigned int* pDotA, unsigned int* pDotB)
{
    unsigned int tmpDot;
    tmpDot = *pDotA;
    *pDotA = *pDotB;
    *pDotB = tmpDot;
    return;
}

/* Debug */
void Dice::checkDots(void)
{
    if((dots.top + dots.bottom) != 7)
    {
        std::cout << "Check Sum Error Top_Bottom" << std::endl;
    }
    if((dots.north + dots.south) != 7)
    {
        std::cout << "Check Sum Error North_South" << std::endl;
    }
    if((dots.east + dots.west) != 7)
    {
        std::cout << "Check Sum Error East_West" << std::endl;
    }
    return;
}

void Dice::showDots(void)
{
    std::cout << "T:" << dots.top  << " S:" << dots.south << " E:" << dots.east << " B:" << dots.bottom  << " N:" << dots.north << " W:" << dots.west << std::endl;
}

int main(void){
    
    int orderCnt  = 0;
    std::string order = "";
    int sum = 0;
    Dice dice;
    
    while(1)
    {
        std::cin >> orderCnt;   /* ????????°????????? */
        if(orderCnt == 0)       /* ????????????????????£?????????????????? */
        {
            break;
        }
        dice.initialize();
        sum = dice.getTop();    /* ???????????????Top?????????sum????????????????¨???? */
        for(int i=0; i < orderCnt; ++i)
        {
            std::cin >> order;  /* ??????????????? */
            dice.roll(&order);
            sum += dice.getTop();
        }
        /* output */
        std::cout << sum << std::endl;
    }
    return 0;
}