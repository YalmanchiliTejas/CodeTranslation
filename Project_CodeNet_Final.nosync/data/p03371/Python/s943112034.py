def modelAnswer(A:int,B:int,C:int,X:int,Y:int) -> int:
   ans = 10**9
   for i in range(10**5+1):
      total = i * 2 * C + max(0,X-i) * A + max(0,Y-i) * B
      ans = min(ans,total)
   return ans

def main():
   A,B,C,X,Y=map(int,input().split())
   print(modelAnswer(A,B,C,X,Y))
if __name__ == '__main__':
   main()