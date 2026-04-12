h,w=input().split()
a=[list(input()) for i in range(int(h))]
for i in zip(*[i for i in zip(*[i for i in a if '#' in i]) if '#' in i]):
    print(''.join(i))