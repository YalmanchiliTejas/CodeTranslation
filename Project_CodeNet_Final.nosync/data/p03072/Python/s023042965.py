N = int(input())
H_list = list(map(int, input().split()))
H_length = len(H_list)
ans_count = 0

for h_i in range(H_length):
    j_list = [j for j in range(h_i)]
    j_list = sorted(j_list, reverse=True)
    i_e = H_list[h_i]
    if len(j_list)==0:
        ans_count = ans_count + 1
        continue
    is_higher = True
    for h_j in j_list:
        if i_e<H_list[h_j]:
            is_higher = False
    if is_higher:
        ans_count = ans_count + 1

print(ans_count)
