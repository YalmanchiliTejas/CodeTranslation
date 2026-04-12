import collections
import copy
N = int(input())
As = [int(input()) for _ in range(N)]
As.sort()
As = collections.deque(As)
small1 = collections.deque()
small2 = collections.deque()
big1 = collections.deque()
big2 = collections.deque()
A1 = copy.copy(As)
A2 = copy.copy(As)
s = A1.popleft()
b = A2.pop()
small1.append(s)
small2.append(s)
big1.append(b)
big2.append(b)
cnt1 = 0
cnt2 = 0
while A1:
    if cnt1%4 == 0:
        b = A1.pop()
        small1.append(b)
        small2.appendleft(b)
        cnt1 += 1
    elif  cnt1%4 == 1:
        b = A1.pop()
        small2.append(b)
        small1.appendleft(b)
        cnt1 += 1
    elif cnt1%4 == 2:
        s = A1.popleft()
        small1.append(s)
        small2.appendleft(s)
        cnt1 += 1
    else:
        s = A1.popleft()
        small2.append(s)
        small1.appendleft(s)
        cnt1 += 1
while A2:
    if cnt2%4 == 0:
        s = A2.popleft()
        big1.append(s)
        big2.appendleft(s)
        cnt2 += 1
    elif  cnt2%4 == 1:
        s = A2.popleft()
        big2.append(s)
        big1.appendleft(s)
        cnt2 += 1
    elif cnt2%4 == 2:
        b = A2.pop()
        big1.append(b)
        big2.appendleft(b)
        cnt2 += 1
    else:
        b = A2.pop()
        big2.append(b)
        big1.appendleft(b)
        cnt2 += 1
anss1 = 0
anss2 = 0
ansb1 = 0
ansb2 = 0
for i in range(N-1):
    anss1 += abs(small1[i+1]-small1[i])
    anss2 += abs(small2[i+1]-small2[i])
    ansb1 += abs(big1[i+1]-big1[i])
    ansb2 += abs(big2[i+1]-big2[i])
print(max(anss1, anss2, ansb1, ansb2))