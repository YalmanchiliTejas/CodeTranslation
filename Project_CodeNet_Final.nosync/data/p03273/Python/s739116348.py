H,W = map(int, input().split())
A = [input() for _ in range(H)]

B = [i for i in A if '#' in i]

C = [i for i in zip(*B) if '#' in i]

for i in zip(*C):
    print(''.join(i))