After deploying, update nginx.conf in the container:

```
docker cp nginx/nginx.conf base-zm-zoneminder-1:/etc/nginx/nginx.conf
```

Then restart the service:
```
docker exec base-zm-zoneminder-1 ps aux | grep 'nginx: master' | awk '{print $2}' | xargs docker exec base-zm-zoneminder-1 kill
```

The updated nginx.conf enables more endpoints (/live, /small) and listens to more ports.
