n = int(input())
nn = pow(2, n)

for i in range(nn):
    if i == 0:
        print("0:")
    else:
        bin_str = "0" + str(n) + "b"
        bin_i = format(i, bin_str)
        ilist = list(bin_i)
        tmplist = []
        for j, bini in enumerate(ilist):
            if bini == '1':
                tmplist.append(n - j - 1)
        tmplist.sort()
        tmp_str = ' '.join(str(tmp) for tmp in tmplist)
        print(str(i) + ": " + tmp_str)

