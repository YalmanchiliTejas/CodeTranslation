N = int(raw_input())
sum = int(0)
maxv = 0
dict = {sum : int(-1)}

for i in range(N):
    val = int(raw_input())
    sum += val
    
    if dict.get(sum, int(-2)) != -2 :
        maxv = max(maxv, i - dict[sum])
    else :
        dict[sum] = i

print maxv