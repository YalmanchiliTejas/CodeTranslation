n = int(input())
h = list(map(int, input().split()))
            
def bubble(inputlist):
    for i in range(len(inputlist)-1):
        if inputlist[i] > inputlist[-1]:
            return False
    return True
cnt = 0
for i in range(n):
    is_candidate = True
    for j in range(i):
        if h[j] > h[i]:
            is_candidate = False
            break
    if is_candidate:
        cnt+=1
print(cnt)