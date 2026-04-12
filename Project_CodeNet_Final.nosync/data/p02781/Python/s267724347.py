N = input()
n = [ int(x) for x in list(N)]

K = int(input())
nl = len(N)
cnt = 0

if K == 1:
    cnt += n[0]   + (nl-1) * 9
elif K == 2 and nl >= 2:
    if nl == 2:
        cnt += (n[0]-1) * 9 + n[1]
    if nl > 2:
        cnt += (nl-1) * (nl-2) * 9 * 9 // 2
        cnt += (n[0]-1) * 9 * (nl-1)
        for i in range(1,nl):
            if n[i] > 0:
                cnt += n[i] + (nl - i -1) * 9
                break
elif K == 3 and  nl >= 3:
    if nl == 3:
        cnt += (n[0]-1) * 9 * 9
        cnt += (n[1]-1) * 9 + n[2]
    elif nl > 3:
        cnt += (nl-1) * (nl-2) * (nl-3) // 6 * 9 * 9 * 9
        cnt += (n[0]-1) * (nl-1) * (nl-2) //2 * 9 * 9
        for i in range(1,nl):
            if n[i] > 0:
                cnt += (nl-i-1) * (nl-i-2) // 2 * 9 * 9
                cnt += (n[i]-1) * (nl-i-1) * 9
                for j in range(i+1,nl):
                    if n[j] > 0:
                        cnt += (nl-j-1) * 9
                        cnt += n[j]
                        break
                break
print (cnt)
