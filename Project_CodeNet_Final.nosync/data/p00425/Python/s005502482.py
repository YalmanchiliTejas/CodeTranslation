cmds = {
    'North': [0, 1, 5, 4],
    'South': [0, 4, 5, 1],
    'East': [0, 3, 5, 2],
    'West': [0, 2, 5, 3],
    'Right': [1, 2, 4, 3],
    'Left': [1, 3, 4, 2]
}

while 1:
    n = int(raw_input())
    if n == 0: break
    nums = range(1, 7)
    ans = 1
    for i in range(n):
        idxs = cmds[raw_input()]
        nums[idxs[0]], nums[idxs[1]], nums[idxs[2]], nums[idxs[3]] = (
                nums[idxs[1]], nums[idxs[2]], nums[idxs[3]], nums[idxs[0]])
        ans += nums[0]
    print ans