# coding: utf-8
# Here your code !
import sys
f = sys.stdin

def North(d):
    d = [d[1]] + [7 -d[0]] + [d[2]]
    return d
      
def East(d):
    d = [7-d[2]] + [d[1]] + [d[0]]
    return d
      
def South(d):
    d = [7-d[1]] + [d[0]] + [d[2]]
    return d
  
def West(d):
    d = [d[2]] + [d[1]] + [7-d[0]]
    return d
  
def Right(d):
    d = [d[0]] + [d[2]] + [7-d[1]]
    return d
  
def Left(d):
    d = [d[0]] + [7-d[2]] + [d[1]]
    return d
  
  
  
while True:
    n = int(f.readline())
    if n == 0:
        break
      
    dice = [1,2,3]
    result = 1
      
    for _ in range(n):
        direction = f.readline().rstrip()
   
        dice = eval(direction+"(dice)")
     
          
        result += dice[0]
      
    print(result)