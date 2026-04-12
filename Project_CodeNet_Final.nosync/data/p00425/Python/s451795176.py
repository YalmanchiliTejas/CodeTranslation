import sys
f = sys.stdin

ope = {'North':(1,5,2,3,0,4)
      ,'East' :(3,1,0,5,4,2)
      ,'West' :(2,1,5,0,4,3)
      ,'South':(4,0,2,3,5,1)
      ,'Right':(0,2,4,1,3,5)
      ,'Left' :(0,3,1,4,2,5)}
while True:
    n = int(f.readline())
    if n == 0:
        break
    xi = [1,2,3,4,5,6]
    ret = 1
    for _ in range(n):
        xi = [xi[i] for i in ope[f.readline().strip()]]
        ret += xi[0]
    
    print(ret)
        