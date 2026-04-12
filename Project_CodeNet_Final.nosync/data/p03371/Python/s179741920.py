
def myAnswer(A:int,B:int,C:int,X:int,Y:int) -> int:
   ans = 0
   both = C * 2
   AB=A+B
   while X!=0 or Y!=0:
      if(X>=1 and Y >=1):
         ans += min(AB,both)
         X-=1
         Y-=1
      elif(X>=1 and Y == 0):
         ans += min(both,A)
         X -= 1
      else:
         ans += min(both,B)
         Y -= 1
   return ans


def modelAnswer():
   tmp=1
def main():
   A,B,C,X,Y=map(int,input().split())
   print(myAnswer(A,B,C,X,Y))
if __name__ == '__main__':
   main()