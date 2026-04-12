"""
何回足されるかで考えればよい。
真っ二つに切っていく。

各項は必ずM未満。
M項以内に必ずループが現れる。
"""
N,X,M = map(int,input().split())
memo1 = set()
memo2 = []
ans = 0
a = X
flag = True
rest = N
while rest > 0:
    if a in memo1 and flag:
        flag = False
        for i in range(len(memo2)):
            if memo2[i] == a:
                loopStart = i
        setSum = 0
        for i in range(loopStart,len(memo2)):
            setSum += memo2[i]**2 % M
        loopStep = len(memo2)-loopStart
        loopCount = rest // loopStep
        ans += loopCount*setSum
        rest -= loopCount*loopStep
    else:
        memo1.add(a)
        memo2.append(a)
        ans += a
        a = a**2%M
        rest -= 1

print(ans)