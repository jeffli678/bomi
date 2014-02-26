#include "mediamisc.hpp"
#include "hwacc.hpp"
#include "videoformat.hpp"
#include "playengine.hpp"
#include "channelmanipulation.hpp"
extern "C" {
#include <player/core.h>
#include <audio/filter/af.h>
#include <video/filter/vf.h>
#include <audio/out/ao.h>
#include <video/decode/dec_video.h>
#include <audio/decode/dec_audio.h>
}

AvInfoObject::AvInfoObject(QObject *parent)
: QObject(parent) {
}

ChapterInfoObject::ChapterInfoObject(const PlayEngine *engine, QObject *parent)
: TrackInfoObject(parent), m_engine(engine) {
	connect(engine, &PlayEngine::currentChapterChanged, this, &ChapterInfoObject::setCurrent);
}

int ChapterInfoObject::time(int i) const {
	return m_engine->chapters().value(i).time();
}

QString ChapterInfoObject::name(int i) const {
	return m_engine->chapters().value(i).name();
}

AudioTrackInfoObject::AudioTrackInfoObject(const PlayEngine *engine, QObject *parent)
: TrackInfoObject(parent) {
	connect(engine, &PlayEngine::currentAudioStreamChanged, this, &AudioTrackInfoObject::setCurrent);
}
