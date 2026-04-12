def actual(n, H):
    count = 0

    for i in range(len(H)):
        if i == 0:
            count += 1
            continue

        me = H[i]
        left_towers = H[:i]

        can_see_the_sea = all([h <= me for h in left_towers])
        count += int(can_see_the_sea)

    return count

n = int(input())
H = list(map(int, input().split()))

print(actual(n, H))