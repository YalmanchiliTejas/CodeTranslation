MOD = 10 ** 9 + 7
INF = 10 ** 10
import sys
sys.setrecursionlimit(100000000)
dy = (-1,0,1,0)
dx = (0,1,0,-1)

def main():
    x = int(input())
    if x == 7 or x == 5 or x == 3:
        print('YES')
    else:
        print('NO')
 
if __name__ =='__main__':
    main()   
