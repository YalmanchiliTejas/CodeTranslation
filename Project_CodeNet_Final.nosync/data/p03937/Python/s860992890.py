h, w = map(int, input().split())
array = [input().count("#") for x in range(h)]
print("Possible" if sum(array) == h + w - 1 else "Impossible")

# 最小の道順でない場合、どこかで寄り道をしている→右、下以外の場所へ移動している