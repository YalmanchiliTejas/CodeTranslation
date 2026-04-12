#template
def inputlist(): return [int(j) for j in input().split()]
#template
N,M = inputlist()
if N== M:
    print("Yes")
else:
    print("No")