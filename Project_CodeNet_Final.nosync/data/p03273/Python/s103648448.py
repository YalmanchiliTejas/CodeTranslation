H,W = map(int,input().split())
A = [input() for _ in range(H)]
#print(A)
A = list(filter(lambda a: any(x=='#' for x in a), A)) 
#print(A)
#print(list(zip(*A)))
A = list(filter(lambda a: any(x=='#' for x in a), zip(*A)))
#print(A)
#print(list(zip(*A)))

for a in zip(*A):
    print("".join(a))

