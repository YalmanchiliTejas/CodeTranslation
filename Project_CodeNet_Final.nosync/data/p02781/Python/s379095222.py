import sys
sys.setrecursionlimit(10**7)

def main():
  s=input()
  k=int(input())
  n=len(s)
  def dp(i,j,smaller):
    # i桁目以降について、0以外の値を残りj個使用可能という状況を考える。i桁目までは決定している。残りn-i桁
    # このときi桁目までの部分が「等しい」か「strict に小さくなっている」かを smaller フラグによって分岐する。
    if n==i: # 0でない数字をk個つかえなかったパターン。
      return 0 if j>0 else 1
    if smaller:# 残りのn-i桁の中からj桁選び好きな数字にできる。j桁以外はすべて0
      if j==0:
        return 1
      elif j==1:
        return (n-i)*9
      elif j==2:
        return ((n-i)*(n-i-1))//2*9**2
      elif j==3:
        return ((n-i)*(n-i-1)*(n-i-2))//6*9**3
    if j==0: # i桁目以降はすべて0で決まり
      return 1
    ret=0
    # i+1桁目が0なら0を使うしかない
    if s[i]=='0':
      ret+=dp(i+1,j,smaller)
    else:
      ret+=dp(i+1,j-1,smaller) # i+1桁目でsと同じ数字を使う
      ret+=(int(s[i])-1)*dp(i+1,j-1,True) # i+1桁目で0より大きくs未満の数字使う
      ret+=dp(i+1,j,True) # i+1桁目で0を使う。
    return ret
  print(dp(0,k,False))
if __name__=='__main__':
  main()
