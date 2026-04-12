N = int(input())
Hs = list(map(int, input().split()))

def is_ocean_view(idx):
    return max(Hs[:idx]) <= Hs[idx]

ocean_views = [is_ocean_view(idx) for idx in range(1, N)]
print(ocean_views.count(True) + 1)