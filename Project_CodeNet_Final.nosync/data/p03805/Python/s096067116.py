def main():

    import itertools
    n, m = map(int,input().split())
    way_lis = []
    for _ in range(m):
        way_lis.append(list(map(int, input().split())))
    #print(way_lis)
    ans = 0

    point_lis = [x for x in range (1, n+1)]
    per_lis = list(itertools.permutations(point_lis))       #町の順列を全パターン作る
    per_1_lis = []
    for lis in per_lis:
        if lis[0] == 1:
            per_1_lis.append(lis)
    #print(per_1_lis)


    for town_set in per_1_lis:           #一つずつ町のセットをチェック
        cnt = 0
        for i in range(n-1):
            way_i = []
            #print(point_lis, point_lis[i])
            way_i.append(town_set[i])
            way_i.append(town_set[i+1]) #way_i = 町iと町i+1をつなぐ道              
            way_i.sort()        #町i/ 町i+1で小さい方を前に
            #print(way_i)
            for way in way_lis:
                #print(way_i, way, way_i==way)
                if way_i == way:
                    cnt += 1
            if cnt == 0:
                break
            elif cnt == n-1:
                ans += 1
    print(ans)
                
            



if __name__ == "__main__":
    main()