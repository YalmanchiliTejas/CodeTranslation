import string

N = int(input())

alphabet = string.ascii_lowercase

SC = [50 for _ in range(len(alphabet))]

for _ in range(N):
    S = input()
    for i, x in enumerate(alphabet):
        SC[i] = min(SC[i], S.count(x))

print("".join([alphabet[i] * c for i, c in enumerate(SC)]))
