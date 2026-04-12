N = int(input())
S = input()

animals_ans = []
# sheep = 1, wolf = 0
def hypo(sheep, ans, w):
    animals = []
    for _ in range(N):
        animals.append(-1)
    animals[0] = sheep
    if sheep + ans != 1:
        if w == 0:
            animals[N-1] = 1
            animals[1] = 1
        else:
            animals[N-1] = 0
            animals[1] = 0
    else:
        if w == 0:
            animals[N-1] = 0
            animals[1] = 1
        else:
            animals[N-1] = 1
            animals[1] = 0
    for n in range(1, N):
        if (animals[n] == 1 and S[n] == 'o') or  (animals[n] == 0 and S[n] == 'x'):
            if n == N-2 and animals[n+1] != animals[n-1]:
                return 0
            elif n == N-1:
                if animals[n-1] != animals[0]:
                    return 0
                else:
                    return animals
            else:
                animals[n+1] = animals[n-1]
        else:
            if n == N-2 and animals[n+1] == animals[n-1]:
                return 0
            elif n == N-1:
                if animals[n-1] == animals[0]:
                    return 0
                else:
                    return animals
            else:
                animals[n+1] = 1 - animals[n-1]

def arr2str(arr):
    st = ''
    for n in arr:
        if n == 1:
            st += 'S'
        else:
            st += 'W'
    return st

ans = 1 if S[0] == 'o' else 0

# how to print the answer...
animals_ans = hypo(1, ans, 0)
if animals_ans == 0:
    animals_ans = hypo(1, ans, 1)
    if animals_ans == 0:
        animals_ans = hypo(0, ans, 0)
        if animals_ans == 0:
            animals_ans = hypo(0, ans, 1)
            if animals_ans == 0:
                print(-1)
            else:
                print(arr2str(animals_ans))
        else:
            print(arr2str(animals_ans))
    else:
        print(arr2str(animals_ans))
else:
    print(arr2str(animals_ans))