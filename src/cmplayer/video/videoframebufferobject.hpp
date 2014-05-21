#ifndef VIDEOFRAMEBUFFEROBJECT_HPP
#define VIDEOFRAMEBUFFEROBJECT_HPP

#include "videoimagepool.hpp"
#include "videoformat.hpp"
#include "opengl/openglframebufferobject.hpp"

class VideoFramebufferObject {
public:
    ~VideoFramebufferObject()
        { Q_ASSERT(QOpenGLContext::currentContext()); delete m_fbo; }
    auto bind() const -> bool { return m_fbo->bind(); }
    auto release() const -> bool { return m_fbo->release(); }
    auto size() const -> QSize { return m_fbo->size(); }
    auto displaySize() const -> QSize { return m_displaySize; }
    auto pts() const -> double { return m_pts; }
    auto texture() const -> const OpenGLTexture2D& { return m_fbo->texture(); }
private:
    OpenGLFramebufferObject *m_fbo = nullptr;
    QSize m_displaySize;
    double m_pts = MP_NOPTS_VALUE;
    friend class VideoFramebufferObjectPool;
};

using VideoFramebufferObjectCache = VideoImageCache<VideoFramebufferObject>;

#endif // VIDEOFRAMEBUFFEROBJECT_HPP