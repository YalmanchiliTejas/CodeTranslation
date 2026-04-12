N, M = map(int, input().split())
A = []
B = []
for _ in range(M):
    a, b = map(int, input().split())
    A.append(a)
    B.append(b)

def search(S, history, counter):
    new_history = [i for i in history]
    new_history.append(S)
    if len(new_history) == N:
        counter += 1
        return counter
        
    for i in range(len(A)):
        if A[i] == S and not B[i] in history:
            counter = search(B[i], new_history, counter)

    for i in range(len(B)):
        if B[i] == S and not A[i] in history:
            counter = search(A[i], new_history, counter)

    return counter

print(search(1, [], 0))
