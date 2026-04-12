n = int(input())
h = list(map(int, input().split()))
print(len(list(filter(lambda b:b==True, list([max(h[:i+1]) <=hi for i, hi in enumerate(h)])))))