#include <iostream>
#include <string>

const int NORMAL_END = 0;	/* Nomal End */
const int ERROR_END  = 1;	/* Error End */

using namespace std;

class Dice
{
public:
	/* Constructor */
	Dice() :
	TopNum   (1),
	southNum (2),
	eastNum  (3),
	westNum  (4),
	northNum (5),
	bottomNum(6)
	{
	}
	
	/* Destructor */
	~Dice()
    {
    }
	
	/** 
	 *  Get Top Number
	 *  @return TopNum Top Number
	 */
	int getTopNum( void )
	{
		return TopNum;
	}
	
	/** 
	 *  Roll to North
	 */
	void roll2North( void )
	{
		int tempNum = TopNum;
		
		TopNum    = southNum;
		southNum  = bottomNum;
		bottomNum = northNum;
		northNum  = tempNum;
		return;
	}
	
	/** 
	 *  Roll to East
	 */
	void roll2East( void )
	{
		int tempNum = TopNum;
		
		TopNum    = westNum;
		westNum   = bottomNum;
		bottomNum = eastNum;
		eastNum   = tempNum;
		return;
	}
	
	/** 
	 *  Roll to West
	 */
	void roll2West( void )
	{
		int tempNum = TopNum;
		
		TopNum    = eastNum;
		eastNum   = bottomNum;
		bottomNum = westNum;
		westNum   = tempNum;
		return;
	}
	
	/** 
	 *  Roll to South
	 */
	void roll2South( void )
	{
		int tempNum = TopNum;
		
		TopNum    = northNum;
		northNum  = bottomNum;
		bottomNum = southNum;
		southNum  = tempNum;
		return;
	}
	
	/** 
	 *  Roll to Right
	 */
	void roll2Right( void )
	{
		int tempNum = southNum;
		
		southNum = eastNum;
		eastNum  = northNum;
		northNum = westNum;
		westNum  = tempNum;
		return;
	}
	
	/** 
	 *  Roll to Left
	 */
	void roll2Left( void )
	{
		int tempNum = southNum;
		
		southNum = westNum;
		westNum  = northNum;
		northNum = eastNum;
		eastNum  = tempNum;
		return;
	}
	
private:
	int TopNum;		/* Numbers on the top of the dice    */
	int southNum;	/* Numbers on the south of the dice  */
	int eastNum;	/* Numbers on the east of the dice   */
	int westNum;	/* Numbers on the west of the dice   */
	int northNum;	/* Numbers on the north of the dice  */
	int bottomNum;	/* Numbers on the bottom of the dice */
};

/** 
 *  Roll to Right
 *  @return NORMAL_END Success
 *  @return ERROR_END  Failure
 */
int main(void)
{
	int dataSetCnt = 0;
	int dataSet;
	string roll;
	
	while( cin >> dataSet )
	{
		/* End Case */
		if( dataSet == 0 )
		{
			break;
		}
		
		/* Abnorml Case */
		if( dataSetCnt > 5 )
		{
			return ERROR_END;
		}
		if( dataSet > 10000 )
		{
			return ERROR_END;
		}
		
		Dice dice;
		int topSum = dice.getTopNum();
		
		/* Roll Dice */
		for( int i = 0; i < dataSet; i++ )
		{
			cin >> roll;
			if ( roll.compare("North") == 0 )
			{
				dice.roll2North();
			}
			else if ( roll.compare("East") == 0 )
			{
				dice.roll2East();
			}
			else if ( roll.compare("South") == 0 )
			{
				dice.roll2South();
			}
			else if ( roll.compare("West") == 0 )
			{
				dice.roll2West();
			}
			else if ( roll.compare("Right") == 0 )
			{
				dice.roll2Right();
			}
			else if ( roll.compare("Left") == 0 )
			{
				dice.roll2Left();
			}
			else
			{
				return ERROR_END;
			}
			topSum += dice.getTopNum();
		}
		
		/* Output */
		cout << topSum << endl;
		
		/* DataSetCnt CountUp */
		++dataSetCnt;
	}
	
	return NORMAL_END;
}