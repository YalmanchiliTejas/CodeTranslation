N,M = map(int, input().split())
path = [[] for i in range(N)] 
for i in range(M):
    nums = list(map(int, input().split()))
    path[nums[0]-1].append(nums[1]-1)
    path[nums[1]-1].append(nums[0]-1)

memo = [] 
def search(idx, memo_str):
    if len(memo_str) == N and memo_str not in memo:
        memo.append(memo_str)
        return
    
    if str(idx) in memo_str:
        return
    
    tmp_memo = memo_str + str(idx)
    
    for num in path[idx]:
        search(num, tmp_memo)

search(0, '')

print(len(memo))