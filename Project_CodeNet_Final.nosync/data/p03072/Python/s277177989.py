from heapq import heappush,heappop

def int_raw():
    return int(input())

def ss_raw():
    return input().split()

def ints_raw():
    return list(map(int, ss_raw()))

N = int_raw()
Hs = ints_raw()
def ans():

    ans =0
    for i in range(len(Hs)):
        is_v = 1
        for j in range(i):
            if Hs[i]<Hs[j]:
                is_v=0
                break
        ans+=is_v

    return ans

print(ans())

