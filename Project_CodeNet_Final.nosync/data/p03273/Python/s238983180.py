H, W = map(int,input().split())
HW = [input() for _ in range(H)]
#print(HW)
#黒がない行は削除して転置,*で文字列を一文字ずつに分解、joinで再結合
HW = ["".join(hw) for hw in zip(*HW) if hw.count("#") > 0]
#転置した後の黒がない行（元の行列の列に対応する）は削除して転置（元の行列に戻る）
HW = ["".join(hw) for hw in zip(*HW) if hw.count("#") > 0]
print("\n".join(HW))#改行を伴って結合