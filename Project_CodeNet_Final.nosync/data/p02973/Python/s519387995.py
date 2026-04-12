N = int(input())
A = []
for _ in range(N):
    A.append(int(input()))

def binsearch(threshold, lst):
    left, right = -1, len(lst)
    while right - left > 1:
        mid = (left + right) // 2
        if lst[mid] < threshold:
            right = mid
        else:
            left = mid
    return right


last=[]
for val in A:
    temp = binsearch(val, last)
    if temp == len(last):
        #last.insert(0, val)
        last.append(val)
    else:
        last[temp] = val
    #print(last)
print(len(last))


