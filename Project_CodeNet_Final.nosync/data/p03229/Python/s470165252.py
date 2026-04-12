from collections import deque
n = int(input())
ai = [int(input()) for i in range(n)]

ai.sort()

deq = deque()
deq.appendleft(ai[0])

#print(ai)
#print()

for i in range(n-1):
    if i % 4 == 0:
        deq.appendleft(ai[n-i//2-1])
        #print(n-i//2-1)
    elif i % 4 == 1:
        deq.append(ai[n-i//2-2])
        #print(n-i//2-2)
    elif i % 4 == 2:
        deq.appendleft(ai[i//2])
        #print(i//2)
    elif i % 4 == 3:
        deq.append(ai[i//2+1])
        #print(i//2+1)
        #print(n-i//3-2)
    #print(deq)
    
ans = 0

#print(deq)

for i in range(n-1):
    ans += abs(deq[i+1] - deq[i])


ai.sort(reverse=True)

deq = deque()
deq.appendleft(ai[0])

#print(ai)
#print()

for i in range(n-1):
    if i % 4 == 0:
        deq.appendleft(ai[n-i//2-1])
        #print(n-i//2-1)
    elif i % 4 == 1:
        deq.append(ai[n-i//2-2])
        #print(n-i//2-2)
    elif i % 4 == 2:
        deq.appendleft(ai[i//2])
        #print(i//2)
    elif i % 4 == 3:
        deq.append(ai[i//2+1])
        #print(i//2+1)
        #print(n-i//3-2)
    #print(deq)
    
ans2 = 0

#print(deq)

for i in range(n-1):
    ans2 += abs(deq[i+1] - deq[i])
#print(ans2)
print(max(ans,ans2))