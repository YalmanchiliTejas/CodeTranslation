import sys

def solve():
      input = sys.stdin.readline
      N, X, M = map(int, input().split())
      D = [False] * M
      roopStart = -1
      now = X
      for i in range(M+1): #ループ検出
            ne = now * now % M
            if D[ne]:
                  roopStart = ne
                  break
            else: 
                  D[ne] = True
                  now = ne
      
      roopL, roopS = 1, 0
      now = roopStart
      for i in range(M+1):
            ne = now * now % M
            roopS += now
            if ne == roopStart: break
            else: 
                  roopL += 1
                  now = ne

      #初期和
      ans = 0
      initialL = 0
      now = X
      for i in range(M+1):
            if i == N: break
            if now != roopStart:
                  ans += now
                  initialL += 1
                  now = now * now % M
            else: break
      if initialL <= N:
            N -= initialL
            roopTimes = N // roopL
            roopRem = N % roopL
            ans += (roopTimes * roopS) 
            now = roopStart
            for j in range(roopRem):
                  ans += now
                  now = now * now % M
            
      print(ans)
      return 0

if __name__ == "__main__":
      solve() 