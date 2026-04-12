N = int(input())
S = input().rstrip()
K = int(input())
 
val = list(S)[K-1]
output=[tmp if tmp == val else '*' for tmp in list(S) ]
 
print("".join(output))