from collections import deque
import bisect
import sys
def I(): return int(sys.stdin.readline())
def LI(): return list(map(int,sys.stdin.readline().split()))
ans = int(0)

N = I()
color = []
a = I()
maxcolor =deque()
maxcolor.append(a)
lena = 1
for i in range(N-1):
    minmaxcolor = maxcolor[0]
    a = I()
    if a<=minmaxcolor:
        maxcolor.appendleft(a)
#        maxcolor.append(a)
        lena += 1
    else:
        acandi = bisect.bisect_left(maxcolor, a)
        maxcolor[acandi-1] = a
        """
        aupper = lena-1
        alower = int(0)
        acandi = aupper//2
        
        for _ in range(aupper+1):
            if maxcolor[acandi]>=a:
                alower = acandi
                acandi = (aupper+acandi+1)//2
            else:
                if aupper - alower <= 1:
                    maxcolor[acandi] = a
                    break
                else:
                    aupper = acandi
                    acandi = (acandi + alower) // 2
        """

#print(maxcolor)
ans = len(maxcolor)
print(ans)

