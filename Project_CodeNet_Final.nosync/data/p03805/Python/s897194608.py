N, M = map(int, input().split())
result = 0
array = [[] for _ in range(N)]

for _ in range(M):
    a, b = map(int, input().split())
    array[a-1].append(b)
    array[b-1].append(a)

def search(x, L):
    LL = list(L)
    global result
    LL.append(x)
    if len(LL) == N:
        result += 1
        return
    for i in range(len(array[x-1])):
        if not array[x-1][i] in L:
            search(array[x-1][i], LL)
        
def main():
    L = []
    search(1, L)
    print(result)

main()
