#import collections
#aa = collections.Counter(a) # list to list
#from itertools import combinations # (string,3) 3回

mod = 10**9 + 7

def readInts():
  return list(map(int,input().split()))
def main():
    a,b,c,x,y = readInts()

    # ABピザは2枚セットで
    c *= 2

    # 1500, 2000, 3800

    if x > y: # 3通りしかない aとbをx,y個ずつ買う ||
    # ピザ2枚セットを大きいほう個買う || 2枚セットを小さいほう買って、残りは大きいほう
        ans = min(a * x + b * y, c * x, c * y + a*(x-y))
    else:
        ans = min(a * x + b * y, c * y, c * x + b * (y-x))
    print(ans)
if __name__ == '__main__':
  main()
