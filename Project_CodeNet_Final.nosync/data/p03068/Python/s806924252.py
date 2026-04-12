N = int(input())
S = input()
K = int(input())
O = ["a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"]
if S.islower():
    if len(S) == N:
        if 1 <= K <= N <= 10:
            W = str(S[K - 1])
            O.remove(W)
            for i in range(24):
                S = S.replace(O[i],"*")
print(S)
                