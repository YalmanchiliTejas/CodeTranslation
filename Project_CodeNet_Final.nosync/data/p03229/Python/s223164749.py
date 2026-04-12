N = int(input())
# n, a, b = [int(i) for i in input().split()]
r = []
for i in range(N):
    A = int(input())
    r.append(A)

r_asc = sorted(r)
r_desc = sorted(r, reverse=True)
row = []
row2 = []

for i in range(N):
    if i % 2 == 0:
        row.append(r_asc[i//2])
        row2.append(r_desc[i//2])
    else:
        row.append(r_desc[i//2])
        row2.append(r_asc[i//2])
row3 = [row[-1]] + row[:-1]
row4 = [row2[-1]] + row2[:-1]
row_diff = [abs(row[i] - row[i-1]) for i in range(1, N)]
row2_diff = [abs(row2[i] - row2[i-1]) for i in range(1, N)]
row3_diff = [abs(row3[i] - row3[i-1]) for i in range(1, N)]
row4_diff = [abs(row4[i] - row4[i-1]) for i in range(1, N)]
print(max(sum(row_diff), sum(row2_diff), sum(row3_diff), sum(row4_diff)))
