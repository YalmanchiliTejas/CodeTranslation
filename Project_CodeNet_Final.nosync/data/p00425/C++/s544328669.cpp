#include <iostream>
#include <string>

class Dice {
public:
    Dice(int label1, int label2, int label3, int label4, int label5, int label6)
    {
        m_label[0] = label1;
        m_label[1] = label2;
        m_label[2] = label3;
        m_label[3] = label4;
        m_label[4] = label5;
        m_label[5] = label6;
    }

    void rollDice(std::string command)
    {
        if (command == "East") {
            // 1->3 3->6 6->4 4->1
            int tmpLabelV = m_label[0];
            m_label[0] = m_label[3];
            m_label[3] = m_label[5];
            m_label[5] = m_label[2];
            m_label[2] = tmpLabelV;
        }
        else if (command == "North") {
            // 1->5 5->6 6->2 2->1
            int tmpLabelV = m_label[0];
            m_label[0] = m_label[1];
            m_label[1] = m_label[5];
            m_label[5] = m_label[4];
            m_label[4] = tmpLabelV;
        }
        else if (command == "South") {
            // 1->2 2->6 6->5 5->1
            int tmpLabelV = m_label[0];
            m_label[0] = m_label[4];
            m_label[4] = m_label[5];
            m_label[5] = m_label[1];
            m_label[1] = tmpLabelV;
        }
        else if (command == "West") {
            // 1->4 4->6 6->3 3->1
            int tmpLabelV = m_label[0];
            m_label[0] = m_label[2];
            m_label[2] = m_label[5];
            m_label[5] = m_label[3];
            m_label[3] = tmpLabelV;
        }
        else if (command == "Right") {
            // 2->4 4->5 5->3 3->2
            int tmpLabelV = m_label[1];
            m_label[1] = m_label[2];
            m_label[2] = m_label[4];
            m_label[4] = m_label[3];
            m_label[3] = tmpLabelV;
        }
        else if (command == "Left") {
            // 2->3 3->5 5->4 4->2
            int tmpLabelV = m_label[1];
            m_label[1] = m_label[3];
            m_label[3] = m_label[4];
            m_label[4] = m_label[2];
            m_label[2] = tmpLabelV;
        }
        return;
    }

    int getNumberOnTop(void)
    {
        return m_label[0];
    }

private:
    int m_label[6];
};

int main()
{
    int count = 0;
    int dataSetSum[5] = {0};
    for(count=0; count<5; count++)
    {
        Dice dice1(1, 2, 3, 4, 5, 6);
        int sum=1;
        int actionNum;
        std::cin >> actionNum;
        if(actionNum == 0)
        {
            break;
        }

        std::string command;

        for (int i = 0; i < actionNum; i++) {
            std::cin >> command;
            dice1.rollDice(command);
            sum += dice1.getNumberOnTop();
        }
        dataSetSum[count] = sum;
    }
    for(int i=0; i<count; i++)
    {
        std::cout << dataSetSum[i] << std::endl;
    }
    return 0;
}