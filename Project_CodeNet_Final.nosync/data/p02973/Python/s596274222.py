#ABC134-E Sequence Decomposing
"""
与えられたリストを反転した場合の広義(重複を許した)LIS(最長増加部分列)
の長さが答え。
"""
import bisect
import sys
readline = sys.stdin.buffer.readline
def even(n): return 1 if n%2==0 else 0


lst1 = []
n = int(readline())
for i in range(n):
    lst1.append(int(readline()))

lst1.reverse() #減少→増加へ

def LIS(lst):
    dp=[]
    for i in lst:
        pos=bisect.bisect_right(dp,i) #rightなら広義、leftなら狭義
        if len(dp)<=pos:
            dp.append(i)
        else:
            dp[pos]=i
    return len(dp)

print(LIS(lst1))